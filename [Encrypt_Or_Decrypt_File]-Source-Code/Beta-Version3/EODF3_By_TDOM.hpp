#include <iostream> //计算机C++语言，标准输入输出函数 Computer C++ language standard input and output functions
#include <fstream> //计算机C++语言，标准文件流输入输出函数 Computer C++ language standard input and output functions of file stream
#include <io.h> //计算机C语言，标准文件流输入输出函数 Computer C language standard input and output functions of file stream
#include <stdio.h>   //计算机C语言标准输入输出函数 Computer C language standard input and output functions
#include <stdlib.h>  //计算机C语言标准库函数 Computer C language standard library functions
#include <string.h>  //计算机C语言字符串处理函数 Computer C language string handling functions
#include <windows.h> //Windows API main function libary

/*******************************************
*                 加密文件
*
* E_SourceFileName    需要加密的文件名
* E_KEY               密钥
* E_TargetFileNewName 加密完成后要保存的文件名
*
* @return  加密成功或失败的数字表示
*
* 0 = 加密失败
* 1 = 加密成功
********************************************/

	int RunEncryptFile(const char *E_SourceFileCharPath, char *E_KEY, char *E_KEY2, char *E_KEY3, char *E_KEY4, const char *E_TargetFileCharPath)
	{
			FILE *FilePointerSource, *FilePointerTarget; //要打开的文件的指针
			char buffer[102400];                           //缓冲区，用于存放从文件读取的数据

			unsigned int FileByteDataSize,                              //每次需要从文件容器中，处理的(数据项目)内容的字节数量
				RTNOC,                                     //运行循环次数 (Run The Number Of Cycles)
				KeyLength = strlen(E_KEY),                 //密钥的长度
				KeyLength2 = strlen(E_KEY2),
				KeyLength3 = strlen(E_KEY3),
				KeyLength4 = strlen(E_KEY4);

			 FilePointerSource = fopen(E_SourceFileCharPath, "rb"); //以二进制方式读取文件
			 if(FilePointerSource == NULL)
			   {
			   printf("File[%s]failed to open, please check whether the file path and name are entered correctly! \n", E_SourceFileCharPath);
			   printf("文件[%s]打开失败，请检查文件路径和名称是否输入正确！\n", E_SourceFileCharPath);
			   getchar();
			   return 0;
			 }

			 FilePointerTarget = fopen(E_TargetFileCharPath, "wb+"); //以二进制方式写入文件
			 if(FilePointerTarget == NULL)
			 {
			   printf("File[%s]creation/write failed! Please check whether the file path and name are entered correctly!\n", E_TargetFileCharPath);
			   printf("文件[%s]创建/写入失败！请检查文件路径和名称是否输入正确！\n", E_TargetFileCharPath);
			   getchar();
			   return 0;
			 }

/*加密算法开始*/

/*****************************************************************************buffer[RTNOC]******************************************************************************/

//运行大型加密模块
//Run large encryption module

//文件和密钥在缓冲区中计算
//The file and key are counted in Buffer

		int NOIEM;                 //初始加密模块次数 (Number of initial encryption modules)
		int	MAX_NOT_E_MODULE = 65; //运行加密模块循环次数 (The maximum number of times the encryption module is running)

		for(NOIEM = 0;NOIEM < MAX_NOT_E_MODULE;NOIEM++)
		{
			while((FileByteDataSize = fread(buffer, 512, KeyLength, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行递增运算
				 {
					buffer[RTNOC] += E_KEY[RTNOC];
				 }
				fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //将buffer中的数据写入文件
			}
			while((FileByteDataSize = fread(buffer, 512, KeyLength, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行递乘运算
				 {
					buffer[RTNOC] *= E_KEY[RTNOC];
				 }
			   fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //将buffer中的数据写入文件
			}
			while((FileByteDataSize = fread(buffer, 512, KeyLength, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行异或运算
				 {
					buffer[RTNOC] ^= E_KEY[RTNOC];
				 }
			   fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //将buffer中的数据写入文件
			}
			  while((FileByteDataSize = fread(buffer, 512, KeyLength, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行递除运算
				 {
					buffer[RTNOC] /= E_KEY[RTNOC];
				 }
			   fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //将buffer中的数据写入文件
			}
			while((FileByteDataSize = fread(buffer, 512, KeyLength, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行递减运算
				 {
					buffer[RTNOC] -= E_KEY[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //将buffer中的数据写入文件
			}

//文件和密钥2在缓冲区中计算
//The file and key2 are counted in Buffer

			while((FileByteDataSize = fread(buffer, 512, KeyLength2, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行递增运算
				 {
					buffer[RTNOC] += E_KEY2[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //将buffer中的数据写入文件
			}
			while((FileByteDataSize = fread(buffer, 512, KeyLength2, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行递乘运算
				 {
					buffer[RTNOC] *= E_KEY2[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //将buffer中的数据写入文件
			}
			while((FileByteDataSize = fread(buffer, 512, KeyLength2, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行异或运算
				 {
					buffer[RTNOC] ^= E_KEY2[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //将buffer中的数据写入文件
			}
			while((FileByteDataSize = fread(buffer, 512, KeyLength2, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行递除运算
				 {
					buffer[RTNOC] /= E_KEY2[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //将buffer中的数据写入文件
			}
			while((FileByteDataSize = fread(buffer, 512, KeyLength2, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行递减运算
				 {
					buffer[RTNOC] -= E_KEY2[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //将buffer中的数据写入文件
			}

//文件和密钥3在缓冲区中计算
//The file and key3 are counted in Buffer

			while((FileByteDataSize = fread(buffer, 512, KeyLength3, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行递增运算
				 {
					buffer[RTNOC] += E_KEY3[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //将buffer中的数据写入文件
			}
			while((FileByteDataSize = fread(buffer, 512, KeyLength3, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行递乘运算
				 {
					buffer[RTNOC] *= E_KEY3[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //将buffer中的数据写入文件
			}
			while((FileByteDataSize = fread(buffer, 512, KeyLength3, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行异或运算
				 {
					buffer[RTNOC] ^= E_KEY3[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //将buffer中的数据写入文件
			}
			while((FileByteDataSize = fread(buffer, 512, KeyLength3, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行递除运算
				 {
					buffer[RTNOC] /= E_KEY3[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //将buffer中的数据写入文件
			}
			while((FileByteDataSize = fread(buffer, 512, KeyLength3, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行递减运算
				 {
					buffer[RTNOC] -= E_KEY3[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //将buffer中的数据写入文件
			}

//文件和密钥4在缓冲区中计算
//The file and key4 are counted in Buffer

			while((FileByteDataSize = fread(buffer, 512, KeyLength4, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行递增运算
				 {
					buffer[RTNOC] += E_KEY4[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //将buffer中的数据写入文件
			}
			while((FileByteDataSize = fread(buffer, 512, KeyLength4, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行递乘运算
				 {
					buffer[RTNOC] *= E_KEY4[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //将buffer中的数据写入文件
			}
			while((FileByteDataSize = fread(buffer, 512, KeyLength4, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行异或运算
				 {
					buffer[RTNOC] ^= E_KEY4[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //将buffer中的数据写入文件
			}
			while((FileByteDataSize = fread(buffer, 512, KeyLength4, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行递除运算
				 {
					buffer[RTNOC] /= E_KEY4[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //将buffer中的数据写入文件
			}
			while((FileByteDataSize = fread(buffer, 512, KeyLength4, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行递减运算
				 {
					buffer[RTNOC] -= E_KEY4[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //将buffer中的数据写入文件
			}
		}

/***********************************************************************************************************************************************************/

/*加密算法结束*/

		  buffer[102400] = {"/x00"}; //Clear File Buffer Space Data
		  fclose(FilePointerSource);
		  fclose(FilePointerTarget);

		  DeleteFile(E_SourceFileCharPath);

		return 1;
	}

	int RunDecryptFile(const char *D_SourceFileCharPath, char *D_KEY, char *D_KEY2, char *D_KEY3, char *D_KEY4, const char *D_TargetFileCharPath)
	{
			FILE *FilePointerSource, *FilePointerTarget; //要打开的文件的指针
			char buffer[102400];                           //缓冲区，用于存放从文件读取的数据

			unsigned int FileByteDataSize,                              //每次需要从文件容器中，处理的(数据项目)内容的字节数量
				RTNOC,                                     //循环次数
				KeyLength = strlen(D_KEY),                 //密钥的长度
				KeyLength2 = strlen(D_KEY2),
				KeyLength3 = strlen(D_KEY3),
				KeyLength4 = strlen(D_KEY4);

			 FilePointerSource = fopen(D_SourceFileCharPath, "rb"); //以二进制方式读取文件
			 if(FilePointerSource == NULL)
			 {
			   printf("File[%s]failed to open, please check whether the file path and name are entered correctly! \n", D_SourceFileCharPath);
			   printf("文件[%s]打开失败，请检查文件路径和名称是否输入正确！\n", D_SourceFileCharPath);
			   getchar();
			   return 0;
			 }

			 FilePointerTarget = fopen(D_TargetFileCharPath, "wb+"); //以二进制方式写入文件
			 if(FilePointerTarget == NULL)
			 {
			   printf("File[%s]creation/write failed! Please check whether the file path and name are entered correctly!\n", D_TargetFileCharPath);
			   printf("文件[%s]创建/写入失败！请检查文件路径和名称是否输入正确！\n", D_TargetFileCharPath);
			   getchar();
			   return 0;
			 }

/*******************************************
*                 解密文件
*
* D_SourceFileName    需要解密的文件名
* D_KEY               密钥
* D_TargetFileNewName 解密完成后要保存的文件名
*
* @return  解密成功或失败的数字表示
*
* 0 = 解密失败
* 1 = 解密成功
********************************************/

/*解密算法开始*/

/***********************************************************************************************************************************************************/

//运行大型解密模块
//Run large decryption module

//文件和密钥在缓冲区中计算
//The file and key are counted in Buffer

		 int NOIDM;                 //初始解密模块次数 (Number of initial decryption modules)
		 int MAX_NOT_D_MODULE = 65; //运行解密模块循环次数 (The maximum number of times the decryption module is running)

		 for(NOIDM = 0;NOIDM < MAX_NOT_D_MODULE;NOIDM++)
		 {
			while((FileByteDataSize = fread(buffer, 512, KeyLength, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行递减运算
				 {
					buffer[RTNOC] -= D_KEY[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
			}
			while((FileByteDataSize = fread(buffer, 512, KeyLength, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行递除运算
				 {
					buffer[RTNOC] /= D_KEY[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //将buffer中的数据写入文件
			}
			while((FileByteDataSize = fread(buffer, 512, KeyLength, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行异或运算
				 {
					buffer[RTNOC] ^= D_KEY[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //将buffer中的数据写入文件
			}
			while((FileByteDataSize = fread(buffer, 512, KeyLength, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行递乘运算
				 {
					buffer[RTNOC] *= D_KEY[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //将buffer中的数据写入文件
			}
			while((FileByteDataSize = fread(buffer, 512, KeyLength, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行递增运算
				 {
					buffer[RTNOC] += D_KEY[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //将buffer中的数据写入文件
			}


//文件和密钥2在缓冲区中计算
//The file and key2 are counted in Buffer

			while((FileByteDataSize = fread(buffer, 512, KeyLength2, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行递减运算
				 {
					buffer[RTNOC] -= D_KEY2[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //将buffer中的数据写入文件
			}
			while((FileByteDataSize = fread(buffer, 512, KeyLength2, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行递除运算
				 {
					buffer[RTNOC] /= D_KEY2[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //将buffer中的数据写入文件
			}
			while((FileByteDataSize = fread(buffer, 512, KeyLength2, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行异或运算
				 {
					buffer[RTNOC] ^= D_KEY2[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //将buffer中的数据写入文件
			}
			while((FileByteDataSize = fread(buffer, 512, KeyLength2, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行递乘运算
				 {
					buffer[RTNOC] *= D_KEY2[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //将buffer中的数据写入文件
			}
			while((FileByteDataSize = fread(buffer, 512, KeyLength2, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行递增运算
				 {
					buffer[RTNOC] += D_KEY2[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //将buffer中的数据写入文件
			}

//文件和密钥3在缓冲区中计算
//The file and key3 are counted in Buffer

			while((FileByteDataSize = fread(buffer, 512, KeyLength3, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行递减运算
				 {
					buffer[RTNOC] -= D_KEY3[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //将buffer中的数据写入文件
			}
			while((FileByteDataSize = fread(buffer, 512, KeyLength3, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行递除运算
				 {
					buffer[RTNOC] /= D_KEY3[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //将buffer中的数据写入文件
			}
			while((FileByteDataSize = fread(buffer, 512, KeyLength3, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行异或运算
				 {
					buffer[RTNOC] ^= D_KEY3[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //将buffer中的数据写入文件
			}
			while((FileByteDataSize = fread(buffer, 512, KeyLength3, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行递乘运算
				 {
					buffer[RTNOC] *= D_KEY3[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //将buffer中的数据写入文件
			}
			while((FileByteDataSize = fread(buffer, 512, KeyLength3, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行递增运算
				 {
					buffer[RTNOC] += D_KEY3[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //将buffer中的数据写入文件
			}

//文件和密钥4在缓冲区中计算
//The file and key4 are counted in Buffer

			while((FileByteDataSize = fread(buffer, 512, KeyLength4, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行递减运算
				 {
					buffer[RTNOC] -= D_KEY4[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //将buffer中的数据写入文件
			}
			while((FileByteDataSize = fread(buffer, 512, KeyLength4, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行递除运算
				 {
					buffer[RTNOC] /= D_KEY4[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //将buffer中的数据写入文件
			}
			while((FileByteDataSize = fread(buffer, 512, KeyLength4, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行异或运算
				 {
					buffer[RTNOC] ^= D_KEY4[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //将buffer中的数据写入文件
			}
			while((FileByteDataSize = fread(buffer, 512, KeyLength4, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行递乘运算
				 {
					buffer[RTNOC] *= D_KEY4[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //将buffer中的数据写入文件
			}
			while((FileByteDataSize = fread(buffer, 512, KeyLength4, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行递增运算
				 {
					buffer[RTNOC] += D_KEY4[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //将buffer中的数据写入文件
			}
		 }

/***********************************************************************************************************************************************************/

/*解密算法结束*/

		  buffer[102400] = {"/x00"}; //Clear Buffer Space Data
		  fclose(FilePointerSource);
		  fclose(FilePointerTarget);

		  DeleteFile(D_SourceFileCharPath);

		return 1;
	}