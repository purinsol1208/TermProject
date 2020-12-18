#include "stdafx.h"

#include <io.h>
#include <fcntl.h>

WordPool* WordPool::instance_ = nullptr;

int main()
{
	_setmode(_fileno(stdout), _O_U8TEXT);
	Editor* editor = new Editor(L"test.txt");
	editor->Start();

	while (true)
	{
		editor->Print();
		std::wstring input_string;
		std::wcin >> input_string;
		if (!editor->InputMsg(input_string))
			break;
	}
}
