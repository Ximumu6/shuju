#pragma once
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <memory.h>
#include "F:/f/shujujiegou/vector/vector_fun.h"
#include "F:/f/shujujiegou/vector/vector.h"

#ifdef __unix
#define fopen_s(pFile,filename,mode) ((*(pFile))=fopen((filename),  (mode)))==NULL



#include"F:/f/shujujiegou/bintree/bintree.h"
class Bitmap//λͼBitmap�� 
{ 
private:
    unsigned char* M;
    Rank N, _sz; //λͼ�ռ�M[]��N*sizeof(char)*8�������к�_sz����Чλ
protected:
    void init(Rank n)
    {
        M = new unsigned char[N = (n + 7) / 8]; memset(M, 0, N); _sz = 0;
    }
public:
    Bitmap(Rank n = 8) { init(n); } //��ָ����������λͼ
    Bitmap(char* file, Rank n = 8)//��ָ����Ĭ�Ϲ�ģ����ָ���ļ��ж�ȡλͼ
    { 
        init(n);
        FILE* fp;
        fopen_s(&fp, file, "r");
        fread(M, sizeof(char), N, fp);
        fclose(fp);
        for (Rank k = 0, _sz = 0; k < n; k++) _sz += test(k);
    }
    ~Bitmap() { delete[] M; M = NULL; _sz = 0; } //����ʱ�ͷ�λͼ�ռ�

    Rank size() { return _sz; }
    void set(Rank k) { expand(k); _sz++; M[k >> 3] |= (0x80 >> (k & 0x07)); }
    void clear(Rank k) { expand(k); _sz--; M[k >> 3] &= ~(0x80 >> (k & 0x07)); }
    bool test(Rank k) { expand(k); return M[k >> 3] & (0x80 >> (k & 0x07)); }

    void dump(char* file) //��λͼ���嵼����ָ�����ļ����Ա�Դ˺����λͼ������ʼ��
    {
        FILE* fp;
        fopen_s(&fp, file, "w");
        fwrite(M, sizeof(char), N, fp);
        fclose(fp);
    }
    char* bits2string(Rank n) //��ǰnλת��Ϊ�ַ�������
    { 
        expand(n - 1); //��ʱ���ܱ����ʵ����λΪbitmap[n - 1]
        char* s = new char[n + 1]; s[n] = '\0'; //�ַ�����ռ�ռ䣬���ϲ�����߸����ͷ�
        for (Rank i = 0; i < n; i++) s[i] = test(i) ? '1' : '0';
        return s; //�����ַ���λ��
    }
    void expand(Rank k)//�������ʵ�Bitmap[k]�ѳ��磬��������
    { 
        if (k < 8 * N) return; //���ڽ��ڣ���������
        Rank oldN = N; unsigned char* oldM = M;
        init(2 * k); //���������ƣ��ӱ�����
        memcpy_s(M, N, oldM, oldN);
        delete[] oldM; //ԭ����ת�����¿ռ�
    }
};//���λͼBitmap��Ķ���
#endif 
