#pragma once
#include <cstddef>
#include <utility>
#include <iostream>
#include <memory>

template <typename T>
struct RawMemory
{
	T * buf;
	size_t cp;

	RawMemory() = delete;
	RawMemory(size_t n) {
		buf = Allocate(n);
		cp = n;
	}
	~RawMemory() {
		Deallocate(buf);
	}
	T * operator + (size_t i) {
		return  buf + i;
	}
	const T * operator + (size_t i) const {
		return buf + i;
	}
	T & operator [](size_t i) {
		return buf[i];
	}
	const T & operator [](size_t i) const {
		return buf[i];
	}
	static T * Allocate(size_t n) {
		return static_cast<T*>(operator new(n * sizeof(T)));
	}
	static void Deallocate(T * buf) {
		operator delete(buf);
	}
	void Swap(RawMemory & other) {
		std::swap(buf, other.buf);
		std::swap(cp, other.cp);
	}
};

template <typename T>
class Vector
{
	RawMemory<T>  data;
	size_t sz;

	static void Construct(void * buf) {
		new(buf)T();
	}
	static void Construct(void * buf, const T & elem) {
		new(buf)T(elem);
	}
	static void Construct(void * buf, T && elem) {
		new(buf)T(std::move(elem));
	}
	static void Destroy(T * buf) {
		buf->~T();
	}
		
public:
	explicit Vector(size_t n = 0)
	:data(n)
	{	
		std::uninitialized_value_construct_n(data.buf, n);
		sz = n;
	}
	Vector(const Vector & other)
	:data(other.sz)
	{		
		std::uninitialized_copy_n(other.data.buf, other.sz, data.buf);
		sz = other.sz;
	}

	~Vector() {
		std::destroy_n(data.buf, sz);
	}
	//строгая гарантия безопасности
	void Reserve(size_t n) {
		if (n > data.cp) {
			RawMemory<T> data2(n);
			std::uninitialized_move_n(data.buf, sz, data2.buf);
			std::destroy_n(data.buf, sz);
			data.Swap(data2);
		}
	}
	//строгая гарантия безовасности
	void Resize(size_t n) {
		Reserve(n); 
		if (sz < n) {
			std::uninitialized_value_construct_n(data + sz, n - sz);
		}
		else if (sz > n) {
			std::destroy_n(data + n, sz - n);
		}
		sz = n;
	}
	//строгая гарантия
	void PushBack(const T & elem) {
		if (sz == data.cp) {
			Reserve(sz == 0 ? 1 : sz * 2);
		}
		new (data + sz)T(elem);
		++sz;
	}
	//строгая гарантия
	void PushBack(T && elem) {
		if (sz == data.cp) {
			Reserve(sz == 0 ? 1 : sz * 2);
		}
		new (data + sz)T(std::move(elem));
		++sz;
	}
	//строгая гарантия
	void PopBack() {
		std::destroy_at(data + sz - 1);
		--sz;
	}
	//строгая гарантия
	void Swap(Vector & other) {
		data.Swap(other.data);
		std::swap(sz, other.sz);
	}
	//базовая гарантия
	Vector & operator = (const Vector & other) {
		if (other.sz > data.cp) {
			Vector tmp(other);
			Swap(tmp);
		}
		else {
			for (size_t i = 0; i < sz && i < other.sz; ++i) {
				data[i] = other[i];
			}
			if (sz < other.sz) {
				std::uninitialized_copy_n(other.data.buf + sz, other.sz - sz, data.buf + sz);//могут быть искл
			}
			else if (sz > other.sz) {
				std::destroy_n(data.buf + other.sz, sz - other.sz);//безопасная
			}
			sz = other.sz;
		}
		return * this;
	}

	size_t Size() const {
		return sz;
	}
	size_t Capacity() const {
		return data.cp;
	}
	const T & operator[](size_t i) const {
		return data[i];
	}
	T & operator[](size_t i) {
		return data[i];
	}
};

