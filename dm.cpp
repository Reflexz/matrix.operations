//
//  dm.cpp
//  dm
//
//  Created by Андрей Мясоеденков on 02.11.13.
//  Copyright (c) 2013 Андрей Мясоеденков. All rights reserved.
//

#include "iostream"
#include "stdio.h"

int kod1, kod2, m1, m2, u1, v1, e=0;
int A[1000], B[1000], C[2000];
long U[3000], V[2000], buffer;

void output (int *M, int kol);
void null (int *M, int kol);
void menu();

int main()
{
    while(true)      //// МЕНЮ выбора операции
    {
        puts("Операции над матрицами\nМеню:\n1 - Операция объединения множеств\n2 - Операция пересечения множеств\n3 - Операция разности множеств\n4 - Операция симметрической разности множеств\n5 - Операция декартового произведения множеств\n6 - Операция дополнения множества");
        scanf("%d", &kod2);
        int m3, p, k;
        switch(kod2)
        {
            case 1:    // операция объединения
            {
                menu();   // вызов меню ввода множеств
                for(int i=0; i<m2; i++)
                {
                    C[i]=B[i];
                }
                m3=m2;
                for(int j=0; j<m1; j++)
                {
                    p=1;
                    for(k=0; k<m3; k++)
                    {
                        if(C[k]==A[j])
                        {
                            p=0;
                            break;
                        }
                    }
                    if(p==1)
                    {
                        C[m3]=A[j];
                        m3++;
                    }
                }
                std::cout << "Ответ: ";
                output(C, m3);    // вывод
                null(C, m3);    // чистка
                null(A, m1);
                null(B, m2);
                break;
            }
            case 2:    // операция пересечения
            {
                menu();   // вызов меню ввода множеств
                m3=0;
                for(int j=0; j<m1; j++)
                {
                    p=1;
                    for(k=0; k<m2; k++)
                    {
                        if(B[k]==A[j])
                        {
                            C[m3]=A[j];
                            m3++;
                        }
                    }
                }
                std::cout << "Ответ: ";
                output(C, m3);    // вывод
                null(C, m3);    // чистка
                null(A, m1);
                null(B, m2);
                break;
            }
            case 3:    // операция разности
            {
                menu();   // вызов меню ввода множеств
                m3=0;
                for(int j=0; j<m1; j++)
                {
                    p=1;
                    for(k=0; k<m2; k++)
                    {
                        if(A[j]==B[k])
                        {
                            p=0;
                            break;
                        }
                    }
                    if(p==1)
                    {
                        C[m3]=A[j];
                        m3++;
                    }
                }
                std::cout << "Ответ: ";
                output(C, m3);    // вывод
                null(C, m3);      // чистка
                null(A, m1);
                null(B, m2);
                break;
            }
            case 4:     // операция симметрической разности
            {
                menu();   // вызов меню ввода множеств
                m3=0;
                for(int j=0; j<m1; j++)   // первый обход
                {
                    p=1;
                    for(k=0; k<m2; k++)
                    {
                        if(A[j]==B[k])
                        {
                            p=0;
                            break;
                        }
                    }
                    if(p==1)
                    {
                        C[m3]=A[j];
                        m3++;
                    }
                }
                for(int j=0; j<m2; j++)   // второй обход
                {
                    p=1;
                    for(k=0; k<m1; k++)
                    {
                        if(B[j]==A[k])
                        {
                            p=0;
                            break;
                        }
                    }
                    if(p==1)
                    {
                        C[m3]=B[j];
                        m3++;
                    }
                }
                std::cout << "Ответ: ";
                output(C, m3);   // вывод
                null(C, m3);     // чистка
                null(A, m1);
                null(B, m2);
                break;
            }
            case 5:    // операция декартового произведения
            {
                menu();   // вызов меню ввода множеств
                int p=0;
                for(int i=0; i<m1; i++)
                {
                    for(int j=0; j<m2; j++)
                    {
                    C[p]=A[i];   p++;
                    C[p]=B[j];   p++;
                    }
                }
           
                std::cout << "Ответ: {";
                p=0;
                for(int i=0; i<m1*m2; i++)  // вывод ответа
                {
                    std::cout << "<" <<C[p];
                    p++;
                    std::cout << "," <<C[p];
                    p++;
                    std::cout << ">";
                }
                std::cout<< "}" << std::endl;
                null(C, m1*m2);     // чистка
                null(A, m1);
                null(B, m2);
                break;
            }
            case 6:    // дополнение?
            {
                menu();   // вызов меню ввода множеств
                for(int j=0; j<m1; j++)
                {
                    U[j]=A[j];
                }
                //    дополнение множества А
                puts("-введите мощность универсума множества A:");
                scanf("%d", &u1);
                v1=0;
                buffer=0;
                int p;
                // заполнение рандомного дополнения
                for(int h=m1; h<m1+u1; h++)
                {
                    p=1;
                    buffer=rand() % 50 + 1;
                // защита от повторов    
                    for(int i=0; i<m1; i++)
                    {
                        if(buffer==U[i])
                        {
                            p=0;
                            break;
                        }
                    }
                    if(p==1)
                    {
                        U[h]=buffer;
                        V[v1]=buffer;
                        v1++;
                    }
                }
                
                // вывод универсума
                std::cout << "Универсум множества А: {";
                for(int i=0; i<m1+u1; i++)
                {
                    std::cout << U[i];
                    if(i<m1+u1-1) std::cout<<", ";
                }
                std::cout<< "}" << std::endl;
                
                // вывод дополнения
                std::cout << "Дополнение множества А: {";
                for(int i=0; i<v1; i++)
                {
                    std::cout << V[i];
                    if(i<v1-1) std::cout<<", ";
                }
                std::cout<< "}" << std::endl;
               
                for(int i=0; i<m1+u1; i++)   // очистка универсума
                {
                    U[i]=0;
                }
                for(int i=0; i<v1; i++)  // очистка дополнения
                {
                    V[i]=0;
                }
                break;
            }
        }
    }
}

void output (int *M, int kol)
{
    std::cout<< "{";
    for(int i=0; i<kol; i++)
    {
        std::cout << M[i];
        if(i<kol-1) std::cout<<", ";
    }
    std::cout<< "}" << std::endl;
}

void null (int *M, int kol)
{
    for(int i=0; i<kol; i++)
    {
        M[i]=0;
    }
}

void menu()
{
    while(true)       //// МЕНЮ задания множества
    {
        puts("Способ задания множеств:\n1 - Перечислительный способ\n2 - Высказывательный способ");
        scanf("%d", &kod1);
        switch(kod1)
        {
            case 1:   // ввод множеств
                do       // множество А
                {
                    puts("-введите мощность множества A:");
                    scanf("%d", &m1);
                } while (m1<0);
                puts("-введите элементы множества A:");
                for(int i=0; i<m1; i++)
                {
                    scanf("%d", &e);
                    A[i]=e;
                }
                
                if(kod2!=6)
                {
                do    // множество В
                {
                    puts("-введите мощность множества B:");
                    scanf("%d", &m2);
                } while (m2<0);
                puts("-введите элементы множества B:");
                for(int i=0; i<m2; i++)
                {
                    scanf("%d", &e);
                    B[i]=e;
                    e=0;
                }
                }
                break;
            case 2:
                
                break;
        }
        break;
    }
}
