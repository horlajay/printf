#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main(void)
{
	int len, len2;

	char *str = "When you invoke GCC, it normarlly does preprocessing, compilation, assembly and linking. The \"overall options\" allow you to stop this process at an intermediate stage. For example, the -c option says not to run the linker. Then the output consists of object files output by the assembler. \n\nOther options are passed on to one stage of processing. Some options control the preprocessor and tothers ther compiler itself. Yet other options control the assembler and linker; most of these are not documented here, since you rarely need to use any of them. \n\nMost of the command line options that you can use with GCC are useful for C programs; when an opton is ony useful eiht another language (usually C ++), the explanation says so explicitly. If the description for a particular option does not mention a source language, you can use that option with all supportd languages. \n\nThe gcc program accepts options and file names as operands. Many options have multi-letter names; therefore multiple single-letter options ma not%d\n";

	len = _printf(str, 8);
	len2 = printf(str, 8);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return(1);
	}
}
