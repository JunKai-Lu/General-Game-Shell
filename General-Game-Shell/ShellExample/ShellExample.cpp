#include "stdafx.h"
#include "GeneralGameShell.h"

using namespace general_game_shell;

int main()
{
	//create shell.
	GameShell a("General Game Shell");

	//create page.
	ShellPage<int>* root = a.CreatePage<int>("root");
	ShellPage<int>* num = a.CreatePage("num", 10);

	//example of add child page.
	root->AddChildPage("num", "number");

	//use add info func to show info.
	root->AddInfoFunc([]() {
		console::Cprintf("=============================================\n", console::color::gray);
		console::Cprintf("    General Game Shell\n", console::color::yellow);
		console::Cprintf("    Copyright @ Junkai-Lu 2016\n", console::color::yellow);
		console::Cprintf("=============================================\n\n", console::color::gray);
	});

	//add function example
	num->AddFunction("ch", [](int& i)->void {
		static int n = 1;
		i = n++;
		std::cout << "this time is " << i << std::endl;
	}, "show the number of this command be executed.");

	//use add descript to rewriter descript of return.
	root->AddDescript("return", "exit");

	a.RunPage("root");
	return 0;
}

