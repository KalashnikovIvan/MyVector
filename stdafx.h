// stdafx.h: включаемый файл для стандартных системных включаемых файлов
// или включаемых файлов для конкретного проекта, которые часто используются, но
// не часто изменяются
//

#pragma once
//#pragma comment(lib, "E:\\Ivan_work\\projects\\MyVector\\packages\\VisualLeakDetector.2.5.0.0\\lib\\native\\address-model-32\\lib\\vld.lib")
//#include "E:\\Ivan_work\\projects\\MyVector\\packages\\VisualLeakDetector.2.5.0.0\\lib\\native\\include\\vld.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
//#ifdef _DEBUG
//#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
//#define new DEBUG_NEW

/*
inline void* __cdecl operator new(unsigned int s)
{
	return ::operator new(s, _NORMAL_BLOCK, __FILE__, __LINE__);
}
*/
#include "targetver.h"

#include <stdio.h>
#include <tchar.h>



// TODO: Установите здесь ссылки на дополнительные заголовки, требующиеся для программы
