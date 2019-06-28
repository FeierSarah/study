#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>

/*文件*/
//fseek  根据文件指针的位置和偏移量来定位文件指针
//int fseek(FILE * stream, long int offset//偏移量, int origin//起始点);
//偏移量有正负，左－右+
//origin=0(起始)  1(当前)   2(末尾)末尾为‘/0’
//int main() 
//{
//	FILE * pFile;
//	pFile = fopen("example.txt", "wb");
//	fputs("This is an apple.", pFile);
//	fseek(pFile, 9, SEEK_SET); 
//	fputs(" sam", pFile);  
//	fclose(pFile); 
//	return 0;
//}

//ftell返回文件指针相对于起始位置的偏移量
//long int ftell(FILE * stream)
//int main() 
//{
//	FILE * pFile;
//	long size;
//	pFile = fopen("myfile.txt", "rb");
//	if (pFile == NULL) perror("Error opening file");
//	else  {
//		fseek(pFile, 0, SEEK_END);// non-portable
//		size=ftell (pFile);
//		fclose (pFile);
//		printf ("Size of myfile.txt: %ld bytes.\n",size);
//	}
//	return 0;
//}

//_stat #include<sys/stat.h>

//int main()
//{
//	char c;
//	FILE *fpr = NULL;
//	FILE *fpw = NULL;
//	fpr = fopen("C:\\Users\\dell\\Desktop1.text", "r");
//	fpw = fopen("C:\\Users\\dell\\Desktop2.text", "r");//不放入循环重复打开或关闭文件
//	//文件不存在，“r”打开为空；“w”打开创建文件；文件存在，“w”打开创建新的空文件
//	//   文件使用方式   含义                                        如果指定文件不存在    指针指向
//	//	“r”（只读）   为了输入数据，打开一个已经存在的文本文件    出错                  文件位置开头
//	//	“w”（只写）   为了输出数据，打开一个文本文件(为空)        建立一个新的文件      文件位置开头
//	//	“a”（追加）   向文本文件尾添加数据                        出错                  文件位置结尾
//	if (fpr == NULL)
//	{
//		printf("open fail\n");
//		return 0;
//	}
//	if (fpw == NULL)
//	{
//		printf("open fail\n");
//		return 0;
//	}
//	while ((c = fgetc(fpr)) != EOF)
//	{
//		putchar(c);
//		fputc(c, fpw);
//	}
//	//文件缓冲区 
//	//ANSIC 标准采用“缓冲文件系统”处理的数据文件的，所谓缓冲文件系统是指系统自动地在内存中为程序中每一个正
//	//在使用的文件开辟一块“文件缓冲区”。从内存向磁盘输出数据会先送到内存中的缓冲区，装满缓冲区后才一起送到
//	//磁盘上。如果从磁盘向计算机读入数据，则从磁盘文件中读取数据输入到内存缓冲区（充满缓冲区），然后再从缓冲
//	//区逐个地将数据送到程序数据区（程序变量等）。缓冲区的大小根据C编译系统决定的。
//	fclose(fpr);
//	fclose(fpw);
//	fpr = NULL;
//	fpw = NULL;
//	return 0;
//}

//int main()
//{
//	int n = 0;
//	char c;
//	FILE *fpr = NULL;
//	FILE *fpw = NULL; 
//	char *buf = NULL;
//	fpr = fopen("C:\\Users\\dell\\Desktop1.text", "r");
//	fpw = fpr = fopen("C:\\Users\\dell\\Desktop1.text", "w");
//	if (fpr == NULL)
//	{
//		printf("null\n");
//		return 0;
//	}
//	/*while (c=(fgetsc(fpr)!=EOF))
//	{
//		n++;
//	}*/
//	rewind(fpr);
//	buf = (char*)malloc(sizeof(char)*(n + 1));
//	fgets(buf, n, fpr);//'\0',取4个字符，剩余一个放\0
//	puts(buf);
//	fputs("hahaha\n", fpw);
//	puts("hahaha\n", fpw);
//	fclose(fpr);
//	fclose(fpw);
//	fpr = NULL;
//	fpw = NULL;
//	return 0;
//}

//字符串——fread,fwrite,fgets
//格式化 二进制fread,fwrite
//       文本  fscanf,fprintf