#include <iostream> //�����C++���ԣ���׼����������� Computer C++ language standard input and output functions
#include <fstream> //�����C++���ԣ���׼�ļ�������������� Computer C++ language standard input and output functions of file stream
#include <io.h> //�����C���ԣ���׼�ļ�������������� Computer C language standard input and output functions of file stream
#include <stdio.h>   //�����C���Ա�׼����������� Computer C language standard input and output functions
#include <stdlib.h>  //�����C���Ա�׼�⺯�� Computer C language standard library functions
#include <string.h>  //�����C�����ַ����������� Computer C language string handling functions
#include <windows.h> //Windows API main function libary

/*******************************************
*                 �����ļ�
*
* E_SourceFileName    ��Ҫ���ܵ��ļ���
* E_KEY               ��Կ
* E_TargetFileNewName ������ɺ�Ҫ������ļ���
*
* @return  ���ܳɹ���ʧ�ܵ����ֱ�ʾ
*
* 0 = ����ʧ��
* 1 = ���ܳɹ�
********************************************/

	int RunEncryptFile(const char *E_SourceFileCharPath, char *E_KEY, char *E_KEY2, char *E_KEY3, char *E_KEY4, const char *E_TargetFileCharPath)
	{
			FILE *FilePointerSource, *FilePointerTarget; //Ҫ�򿪵��ļ���ָ��
			char buffer[102400];                           //�����������ڴ�Ŵ��ļ���ȡ������

			unsigned int FileByteDataSize,                              //ÿ����Ҫ���ļ������У�������(������Ŀ)���ݵ��ֽ�����
				RTNOC,                                     //����ѭ������ (Run The Number Of Cycles)
				KeyLength = strlen(E_KEY),                 //��Կ�ĳ���
				KeyLength2 = strlen(E_KEY2),
				KeyLength3 = strlen(E_KEY3),
				KeyLength4 = strlen(E_KEY4);

			 FilePointerSource = fopen(E_SourceFileCharPath, "rb"); //�Զ����Ʒ�ʽ��ȡ�ļ�
			 if(FilePointerSource == NULL)
			   {
			   printf("File[%s]failed to open, please check whether the file path and name are entered correctly! \n", E_SourceFileCharPath);
			   printf("�ļ�[%s]��ʧ�ܣ������ļ�·���������Ƿ�������ȷ��\n", E_SourceFileCharPath);
			   getchar();
			   return 0;
			 }

			 FilePointerTarget = fopen(E_TargetFileCharPath, "wb+"); //�Զ����Ʒ�ʽд���ļ�
			 if(FilePointerTarget == NULL)
			 {
			   printf("File[%s]creation/write failed! Please check whether the file path and name are entered correctly!\n", E_TargetFileCharPath);
			   printf("�ļ�[%s]����/д��ʧ�ܣ������ļ�·���������Ƿ�������ȷ��\n", E_TargetFileCharPath);
			   getchar();
			   return 0;
			 }

/*�����㷨��ʼ*/

/*****************************************************************************buffer[RTNOC]******************************************************************************/

//���д��ͼ���ģ��
//Run large encryption module

//�ļ�����Կ�ڻ������м���
//The file and key are counted in Buffer

		int NOIEM;                 //��ʼ����ģ����� (Number of initial encryption modules)
		int	MAX_NOT_E_MODULE = 65; //���м���ģ��ѭ������ (The maximum number of times the encryption module is running)

		for(NOIEM = 0;NOIEM < MAX_NOT_E_MODULE;NOIEM++)
		{
			while((FileByteDataSize = fread(buffer, 512, KeyLength, FilePointerSource)) > 0) //���ϵش��ļ��ж�ȡ KeyLength ���ȵ����ݣ����浽buffer��ֱ���ļ�����
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //��buffer�е��������ֽڵĺ�E_KEY���е�������
				 {
					buffer[RTNOC] += E_KEY[RTNOC];
				 }
				fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //��buffer�е�����д���ļ�
			}
			while((FileByteDataSize = fread(buffer, 512, KeyLength, FilePointerSource)) > 0) //���ϵش��ļ��ж�ȡ KeyLength ���ȵ����ݣ����浽buffer��ֱ���ļ�����
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //��buffer�е��������ֽڵĺ�E_KEY���еݳ�����
				 {
					buffer[RTNOC] *= E_KEY[RTNOC];
				 }
			   fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //��buffer�е�����д���ļ�
			}
			while((FileByteDataSize = fread(buffer, 512, KeyLength, FilePointerSource)) > 0) //���ϵش��ļ��ж�ȡ KeyLength ���ȵ����ݣ����浽buffer��ֱ���ļ�����
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //��buffer�е��������ֽڵĺ�E_KEY�����������
				 {
					buffer[RTNOC] ^= E_KEY[RTNOC];
				 }
			   fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //��buffer�е�����д���ļ�
			}
			  while((FileByteDataSize = fread(buffer, 512, KeyLength, FilePointerSource)) > 0) //���ϵش��ļ��ж�ȡ KeyLength ���ȵ����ݣ����浽buffer��ֱ���ļ�����
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //��buffer�е��������ֽڵĺ�E_KEY���еݳ�����
				 {
					buffer[RTNOC] /= E_KEY[RTNOC];
				 }
			   fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //��buffer�е�����д���ļ�
			}
			while((FileByteDataSize = fread(buffer, 512, KeyLength, FilePointerSource)) > 0) //���ϵش��ļ��ж�ȡ KeyLength ���ȵ����ݣ����浽buffer��ֱ���ļ�����
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //��buffer�е��������ֽڵĺ�E_KEY���еݼ�����
				 {
					buffer[RTNOC] -= E_KEY[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //��buffer�е�����д���ļ�
			}

//�ļ�����Կ2�ڻ������м���
//The file and key2 are counted in Buffer

			while((FileByteDataSize = fread(buffer, 512, KeyLength2, FilePointerSource)) > 0) //���ϵش��ļ��ж�ȡ KeyLength ���ȵ����ݣ����浽buffer��ֱ���ļ�����
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //��buffer�е��������ֽڵĺ�E_KEY���е�������
				 {
					buffer[RTNOC] += E_KEY2[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //��buffer�е�����д���ļ�
			}
			while((FileByteDataSize = fread(buffer, 512, KeyLength2, FilePointerSource)) > 0) //���ϵش��ļ��ж�ȡ KeyLength ���ȵ����ݣ����浽buffer��ֱ���ļ�����
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //��buffer�е��������ֽڵĺ�E_KEY���еݳ�����
				 {
					buffer[RTNOC] *= E_KEY2[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //��buffer�е�����д���ļ�
			}
			while((FileByteDataSize = fread(buffer, 512, KeyLength2, FilePointerSource)) > 0) //���ϵش��ļ��ж�ȡ KeyLength ���ȵ����ݣ����浽buffer��ֱ���ļ�����
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //��buffer�е��������ֽڵĺ�E_KEY�����������
				 {
					buffer[RTNOC] ^= E_KEY2[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //��buffer�е�����д���ļ�
			}
			while((FileByteDataSize = fread(buffer, 512, KeyLength2, FilePointerSource)) > 0) //���ϵش��ļ��ж�ȡ KeyLength ���ȵ����ݣ����浽buffer��ֱ���ļ�����
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //��buffer�е��������ֽڵĺ�E_KEY���еݳ�����
				 {
					buffer[RTNOC] /= E_KEY2[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //��buffer�е�����д���ļ�
			}
			while((FileByteDataSize = fread(buffer, 512, KeyLength2, FilePointerSource)) > 0) //���ϵش��ļ��ж�ȡ KeyLength ���ȵ����ݣ����浽buffer��ֱ���ļ�����
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //��buffer�е��������ֽڵĺ�E_KEY���еݼ�����
				 {
					buffer[RTNOC] -= E_KEY2[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //��buffer�е�����д���ļ�
			}

//�ļ�����Կ3�ڻ������м���
//The file and key3 are counted in Buffer

			while((FileByteDataSize = fread(buffer, 512, KeyLength3, FilePointerSource)) > 0) //���ϵش��ļ��ж�ȡ KeyLength ���ȵ����ݣ����浽buffer��ֱ���ļ�����
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //��buffer�е��������ֽڵĺ�E_KEY���е�������
				 {
					buffer[RTNOC] += E_KEY3[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //��buffer�е�����д���ļ�
			}
			while((FileByteDataSize = fread(buffer, 512, KeyLength3, FilePointerSource)) > 0) //���ϵش��ļ��ж�ȡ KeyLength ���ȵ����ݣ����浽buffer��ֱ���ļ�����
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //��buffer�е��������ֽڵĺ�E_KEY���еݳ�����
				 {
					buffer[RTNOC] *= E_KEY3[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //��buffer�е�����д���ļ�
			}
			while((FileByteDataSize = fread(buffer, 512, KeyLength3, FilePointerSource)) > 0) //���ϵش��ļ��ж�ȡ KeyLength ���ȵ����ݣ����浽buffer��ֱ���ļ�����
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //��buffer�е��������ֽڵĺ�E_KEY�����������
				 {
					buffer[RTNOC] ^= E_KEY3[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //��buffer�е�����д���ļ�
			}
			while((FileByteDataSize = fread(buffer, 512, KeyLength3, FilePointerSource)) > 0) //���ϵش��ļ��ж�ȡ KeyLength ���ȵ����ݣ����浽buffer��ֱ���ļ�����
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //��buffer�е��������ֽڵĺ�E_KEY���еݳ�����
				 {
					buffer[RTNOC] /= E_KEY3[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //��buffer�е�����д���ļ�
			}
			while((FileByteDataSize = fread(buffer, 512, KeyLength3, FilePointerSource)) > 0) //���ϵش��ļ��ж�ȡ KeyLength ���ȵ����ݣ����浽buffer��ֱ���ļ�����
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //��buffer�е��������ֽڵĺ�E_KEY���еݼ�����
				 {
					buffer[RTNOC] -= E_KEY3[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //��buffer�е�����д���ļ�
			}

//�ļ�����Կ4�ڻ������м���
//The file and key4 are counted in Buffer

			while((FileByteDataSize = fread(buffer, 512, KeyLength4, FilePointerSource)) > 0) //���ϵش��ļ��ж�ȡ KeyLength ���ȵ����ݣ����浽buffer��ֱ���ļ�����
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //��buffer�е��������ֽڵĺ�E_KEY���е�������
				 {
					buffer[RTNOC] += E_KEY4[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //��buffer�е�����д���ļ�
			}
			while((FileByteDataSize = fread(buffer, 512, KeyLength4, FilePointerSource)) > 0) //���ϵش��ļ��ж�ȡ KeyLength ���ȵ����ݣ����浽buffer��ֱ���ļ�����
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //��buffer�е��������ֽڵĺ�E_KEY���еݳ�����
				 {
					buffer[RTNOC] *= E_KEY4[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //��buffer�е�����д���ļ�
			}
			while((FileByteDataSize = fread(buffer, 512, KeyLength4, FilePointerSource)) > 0) //���ϵش��ļ��ж�ȡ KeyLength ���ȵ����ݣ����浽buffer��ֱ���ļ�����
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //��buffer�е��������ֽڵĺ�E_KEY�����������
				 {
					buffer[RTNOC] ^= E_KEY4[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //��buffer�е�����д���ļ�
			}
			while((FileByteDataSize = fread(buffer, 512, KeyLength4, FilePointerSource)) > 0) //���ϵش��ļ��ж�ȡ KeyLength ���ȵ����ݣ����浽buffer��ֱ���ļ�����
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //��buffer�е��������ֽڵĺ�E_KEY���еݳ�����
				 {
					buffer[RTNOC] /= E_KEY4[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //��buffer�е�����д���ļ�
			}
			while((FileByteDataSize = fread(buffer, 512, KeyLength4, FilePointerSource)) > 0) //���ϵش��ļ��ж�ȡ KeyLength ���ȵ����ݣ����浽buffer��ֱ���ļ�����
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //��buffer�е��������ֽڵĺ�E_KEY���еݼ�����
				 {
					buffer[RTNOC] -= E_KEY4[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //��buffer�е�����д���ļ�
			}
		}

/***********************************************************************************************************************************************************/

/*�����㷨����*/

		  buffer[102400] = {"/x00"}; //Clear File Buffer Space Data
		  fclose(FilePointerSource);
		  fclose(FilePointerTarget);

		  DeleteFile(E_SourceFileCharPath);

		return 1;
	}

	int RunDecryptFile(const char *D_SourceFileCharPath, char *D_KEY, char *D_KEY2, char *D_KEY3, char *D_KEY4, const char *D_TargetFileCharPath)
	{
			FILE *FilePointerSource, *FilePointerTarget; //Ҫ�򿪵��ļ���ָ��
			char buffer[102400];                           //�����������ڴ�Ŵ��ļ���ȡ������

			unsigned int FileByteDataSize,                              //ÿ����Ҫ���ļ������У�������(������Ŀ)���ݵ��ֽ�����
				RTNOC,                                     //ѭ������
				KeyLength = strlen(D_KEY),                 //��Կ�ĳ���
				KeyLength2 = strlen(D_KEY2),
				KeyLength3 = strlen(D_KEY3),
				KeyLength4 = strlen(D_KEY4);

			 FilePointerSource = fopen(D_SourceFileCharPath, "rb"); //�Զ����Ʒ�ʽ��ȡ�ļ�
			 if(FilePointerSource == NULL)
			 {
			   printf("File[%s]failed to open, please check whether the file path and name are entered correctly! \n", D_SourceFileCharPath);
			   printf("�ļ�[%s]��ʧ�ܣ������ļ�·���������Ƿ�������ȷ��\n", D_SourceFileCharPath);
			   getchar();
			   return 0;
			 }

			 FilePointerTarget = fopen(D_TargetFileCharPath, "wb+"); //�Զ����Ʒ�ʽд���ļ�
			 if(FilePointerTarget == NULL)
			 {
			   printf("File[%s]creation/write failed! Please check whether the file path and name are entered correctly!\n", D_TargetFileCharPath);
			   printf("�ļ�[%s]����/д��ʧ�ܣ������ļ�·���������Ƿ�������ȷ��\n", D_TargetFileCharPath);
			   getchar();
			   return 0;
			 }

/*******************************************
*                 �����ļ�
*
* D_SourceFileName    ��Ҫ���ܵ��ļ���
* D_KEY               ��Կ
* D_TargetFileNewName ������ɺ�Ҫ������ļ���
*
* @return  ���ܳɹ���ʧ�ܵ����ֱ�ʾ
*
* 0 = ����ʧ��
* 1 = ���ܳɹ�
********************************************/

/*�����㷨��ʼ*/

/***********************************************************************************************************************************************************/

//���д��ͽ���ģ��
//Run large decryption module

//�ļ�����Կ�ڻ������м���
//The file and key are counted in Buffer

		 int NOIDM;                 //��ʼ����ģ����� (Number of initial decryption modules)
		 int MAX_NOT_D_MODULE = 65; //���н���ģ��ѭ������ (The maximum number of times the decryption module is running)

		 for(NOIDM = 0;NOIDM < MAX_NOT_D_MODULE;NOIDM++)
		 {
			while((FileByteDataSize = fread(buffer, 512, KeyLength, FilePointerSource)) > 0) //���ϵش��ļ��ж�ȡ KeyLength ���ȵ����ݣ����浽buffer��ֱ���ļ�����
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //��buffer�е��������ֽڵĺ�E_KEY���еݼ�����
				 {
					buffer[RTNOC] -= D_KEY[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteData, FilePointerTarget); //��buffer�е�����д���ļ�
			}
			while((FileByteDataSize = fread(buffer, 512, KeyLength, FilePointerSource)) > 0) //���ϵش��ļ��ж�ȡ KeyLength ���ȵ����ݣ����浽buffer��ֱ���ļ�����
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //��buffer�е��������ֽڵĺ�E_KEY���еݳ�����
				 {
					buffer[RTNOC] /= D_KEY[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //��buffer�е�����д���ļ�
			}
			while((FileByteDataSize = fread(buffer, 512, KeyLength, FilePointerSource)) > 0) //���ϵش��ļ��ж�ȡ KeyLength ���ȵ����ݣ����浽buffer��ֱ���ļ�����
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //��buffer�е��������ֽڵĺ�E_KEY�����������
				 {
					buffer[RTNOC] ^= D_KEY[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //��buffer�е�����д���ļ�
			}
			while((FileByteDataSize = fread(buffer, 512, KeyLength, FilePointerSource)) > 0) //���ϵش��ļ��ж�ȡ KeyLength ���ȵ����ݣ����浽buffer��ֱ���ļ�����
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //��buffer�е��������ֽڵĺ�E_KEY���еݳ�����
				 {
					buffer[RTNOC] *= D_KEY[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //��buffer�е�����д���ļ�
			}
			while((FileByteDataSize = fread(buffer, 512, KeyLength, FilePointerSource)) > 0) //���ϵش��ļ��ж�ȡ KeyLength ���ȵ����ݣ����浽buffer��ֱ���ļ�����
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //��buffer�е��������ֽڵĺ�E_KEY���е�������
				 {
					buffer[RTNOC] += D_KEY[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //��buffer�е�����д���ļ�
			}


//�ļ�����Կ2�ڻ������м���
//The file and key2 are counted in Buffer

			while((FileByteDataSize = fread(buffer, 512, KeyLength2, FilePointerSource)) > 0) //���ϵش��ļ��ж�ȡ KeyLength ���ȵ����ݣ����浽buffer��ֱ���ļ�����
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //��buffer�е��������ֽڵĺ�E_KEY���еݼ�����
				 {
					buffer[RTNOC] -= D_KEY2[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //��buffer�е�����д���ļ�
			}
			while((FileByteDataSize = fread(buffer, 512, KeyLength2, FilePointerSource)) > 0) //���ϵش��ļ��ж�ȡ KeyLength ���ȵ����ݣ����浽buffer��ֱ���ļ�����
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //��buffer�е��������ֽڵĺ�E_KEY���еݳ�����
				 {
					buffer[RTNOC] /= D_KEY2[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //��buffer�е�����д���ļ�
			}
			while((FileByteDataSize = fread(buffer, 512, KeyLength2, FilePointerSource)) > 0) //���ϵش��ļ��ж�ȡ KeyLength ���ȵ����ݣ����浽buffer��ֱ���ļ�����
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //��buffer�е��������ֽڵĺ�E_KEY�����������
				 {
					buffer[RTNOC] ^= D_KEY2[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //��buffer�е�����д���ļ�
			}
			while((FileByteDataSize = fread(buffer, 512, KeyLength2, FilePointerSource)) > 0) //���ϵش��ļ��ж�ȡ KeyLength ���ȵ����ݣ����浽buffer��ֱ���ļ�����
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //��buffer�е��������ֽڵĺ�E_KEY���еݳ�����
				 {
					buffer[RTNOC] *= D_KEY2[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //��buffer�е�����д���ļ�
			}
			while((FileByteDataSize = fread(buffer, 512, KeyLength2, FilePointerSource)) > 0) //���ϵش��ļ��ж�ȡ KeyLength ���ȵ����ݣ����浽buffer��ֱ���ļ�����
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //��buffer�е��������ֽڵĺ�E_KEY���е�������
				 {
					buffer[RTNOC] += D_KEY2[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //��buffer�е�����д���ļ�
			}

//�ļ�����Կ3�ڻ������м���
//The file and key3 are counted in Buffer

			while((FileByteDataSize = fread(buffer, 512, KeyLength3, FilePointerSource)) > 0) //���ϵش��ļ��ж�ȡ KeyLength ���ȵ����ݣ����浽buffer��ֱ���ļ�����
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //��buffer�е��������ֽڵĺ�E_KEY���еݼ�����
				 {
					buffer[RTNOC] -= D_KEY3[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //��buffer�е�����д���ļ�
			}
			while((FileByteDataSize = fread(buffer, 512, KeyLength3, FilePointerSource)) > 0) //���ϵش��ļ��ж�ȡ KeyLength ���ȵ����ݣ����浽buffer��ֱ���ļ�����
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //��buffer�е��������ֽڵĺ�E_KEY���еݳ�����
				 {
					buffer[RTNOC] /= D_KEY3[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //��buffer�е�����д���ļ�
			}
			while((FileByteDataSize = fread(buffer, 512, KeyLength3, FilePointerSource)) > 0) //���ϵش��ļ��ж�ȡ KeyLength ���ȵ����ݣ����浽buffer��ֱ���ļ�����
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //��buffer�е��������ֽڵĺ�E_KEY�����������
				 {
					buffer[RTNOC] ^= D_KEY3[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //��buffer�е�����д���ļ�
			}
			while((FileByteDataSize = fread(buffer, 512, KeyLength3, FilePointerSource)) > 0) //���ϵش��ļ��ж�ȡ KeyLength ���ȵ����ݣ����浽buffer��ֱ���ļ�����
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //��buffer�е��������ֽڵĺ�E_KEY���еݳ�����
				 {
					buffer[RTNOC] *= D_KEY3[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //��buffer�е�����д���ļ�
			}
			while((FileByteDataSize = fread(buffer, 512, KeyLength3, FilePointerSource)) > 0) //���ϵش��ļ��ж�ȡ KeyLength ���ȵ����ݣ����浽buffer��ֱ���ļ�����
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //��buffer�е��������ֽڵĺ�E_KEY���е�������
				 {
					buffer[RTNOC] += D_KEY3[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //��buffer�е�����д���ļ�
			}

//�ļ�����Կ4�ڻ������м���
//The file and key4 are counted in Buffer

			while((FileByteDataSize = fread(buffer, 512, KeyLength4, FilePointerSource)) > 0) //���ϵش��ļ��ж�ȡ KeyLength ���ȵ����ݣ����浽buffer��ֱ���ļ�����
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //��buffer�е��������ֽڵĺ�E_KEY���еݼ�����
				 {
					buffer[RTNOC] -= D_KEY4[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //��buffer�е�����д���ļ�
			}
			while((FileByteDataSize = fread(buffer, 512, KeyLength4, FilePointerSource)) > 0) //���ϵش��ļ��ж�ȡ KeyLength ���ȵ����ݣ����浽buffer��ֱ���ļ�����
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //��buffer�е��������ֽڵĺ�E_KEY���еݳ�����
				 {
					buffer[RTNOC] /= D_KEY4[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //��buffer�е�����д���ļ�
			}
			while((FileByteDataSize = fread(buffer, 512, KeyLength4, FilePointerSource)) > 0) //���ϵش��ļ��ж�ȡ KeyLength ���ȵ����ݣ����浽buffer��ֱ���ļ�����
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //��buffer�е��������ֽڵĺ�E_KEY�����������
				 {
					buffer[RTNOC] ^= D_KEY4[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //��buffer�е�����д���ļ�
			}
			while((FileByteDataSize = fread(buffer, 512, KeyLength4, FilePointerSource)) > 0) //���ϵش��ļ��ж�ȡ KeyLength ���ȵ����ݣ����浽buffer��ֱ���ļ�����
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //��buffer�е��������ֽڵĺ�E_KEY���еݳ�����
				 {
					buffer[RTNOC] *= D_KEY4[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //��buffer�е�����д���ļ�
			}
			while((FileByteDataSize = fread(buffer, 512, KeyLength4, FilePointerSource)) > 0) //���ϵش��ļ��ж�ȡ KeyLength ���ȵ����ݣ����浽buffer��ֱ���ļ�����
			{
				 for(RTNOC = 0; RTNOC < FileByteDataSize; RTNOC++) //��buffer�е��������ֽڵĺ�E_KEY���е�������
				 {
					buffer[RTNOC] += D_KEY4[RTNOC];
				 }
			  fwrite(buffer, 512, FileByteDataSize, FilePointerTarget); //��buffer�е�����д���ļ�
			}
		 }

/***********************************************************************************************************************************************************/

/*�����㷨����*/

		  buffer[102400] = {"/x00"}; //Clear Buffer Space Data
		  fclose(FilePointerSource);
		  fclose(FilePointerTarget);

		  DeleteFile(D_SourceFileCharPath);

		return 1;
	}