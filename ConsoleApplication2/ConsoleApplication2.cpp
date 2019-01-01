// ConsoleApplication2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "windows.h"
#include "stdio.h"

#define DEVICE_TYPE_FROM_CTL_CODE(ctrlCode)     (((DWORD)(ctrlCode & 0xffff0000)) >> 16)
#define ACCESS_FROM_CTL_CODE(ctrlCode)			(((DWORD)(ctrlCode & 0xC000)) >> 14)
#define FUNCTION_FROM_CTL_CODE(ctrlCode)		(((DWORD)(ctrlCode & 0x3ffc)) >> 2)
#define METHOD_FROM_CTL_CODE(ctrlCode)          ((DWORD) (ctrlCode & 3))

INT main(INT argc,PCHAR argv[])
{	
	DWORD IoctlNum = 0;

	DWORD DeviceType = 0;
	DWORD Access = 0;
	DWORD Function = 0;
	DWORD Method = 0;
	
	if (argc != 2)
	{
		return puts("usage:dectl.exe IOCTL_Number\n");
	}

	IoctlNum = atoi(argv[1]);

	DeviceType = DEVICE_TYPE_FROM_CTL_CODE(IoctlNum);
	Access = ACCESS_FROM_CTL_CODE(IoctlNum);
	Function = FUNCTION_FROM_CTL_CODE(IoctlNum);
	Method = METHOD_FROM_CTL_CODE(IoctlNum);

	printf("Device Type:0x%x\nAccess:0x%x\nFunction:0x%x\nMethod:0x%x\n",
		DeviceType,
		Access,
		Function,
		Method);

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
