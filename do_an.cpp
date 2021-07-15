#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define max 50
int Nhapmatran(float M[max][max],int &n,char fileName[max]){
    FILE *file;
    file = fopen(fileName,"r");
    if(file == NULL){
        printf("File ko to ton tai\n");
        return 0;
    }
    fscanf(file,"%d",&n);
    for(int i = 0; i < n ; i++){
        for(int j = 0 ; j < n+1 ; j++){
            if(!feof(file)) fscanf(file,"%f",&M[i][j]);
            else{
                printf("Matran khong hop le\n");
                fclose(file);
                return 0;
            }
        }
    }
    fclose(file);
    return 1;   
}

void Xuatmatran(float C[max][max], int n, FILE *f)
{
    fprintf(f, "%d\n" , n);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            fprintf(f, "%d ", C[i][j]);
        }
        fprintf(f,"\n");
    }

    fclose(f);
}
void GhiVaoFile(float *C, int n, FILE *f)
{

    for(int i = 0; i < n; i++)
    {
            fprintf(f, "X[%d] = %.3f\n",i, C[i]);
      }

    fclose(f);
}
void ScreenShow(float A[max][max], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n+1; j++)
        {
            cout << A[i][j] << " ";
        }
         cout << "\n";
    }
}
void print(float A[max][max], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << A[i][j] << " ";
        }
         cout << "\n";
    }
}

void Gauss_Jordan(float A[max][max], int n, float C[max])
{
	float tmp[max][max];
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n+1 ; j++)
	    	tmp[i][j] = A[i][j];
	}
    for(int i = 0; i < n; i++)
    {
          if(tmp[i][i] == 0)
          {
               cout << "Mathematical Error!";
               //exit(0);
          }
          for(int j = 0; j < n; j++)
          {
               if(i != j)
               {
                    float ratio = tmp[j][i]/tmp[i][i];
                    for(int k = 1; k <= n + 1; k++)
                    {
                        tmp[j][k] = tmp[j][k] - ratio * tmp[i][k];
                    }
          }
    }
}
    cout << "Bien doi ve ma tran tam giac : " << endl;
    
   print(tmp,n);
   cout << endl;
   cout << "Ta dc nghiem la : " << endl;
    for(int i = 0; i < n; i++)
    {
    //	cout << A[i][n] / A[i][i];
        C[i] = tmp[i][n] / tmp[i][i];
        cout << "X[" << i << "] = " << C[i] << "\n";
    }
}

float det( float m[max][max], int n) {
   float d = 0;
   float dummy[max][max];
   if (n == 2) return ((m[0][0] * m[1][1]) - (m[1][0] * m[0][1]));
   else {
      for (int x = 0; x < n; x++) {
         int subi = 0;
         for (int i = 1; i < n; i++) {
            int  subj = 0;
            for (int j = 0; j < n; j++) {
               if (j == x)
               continue;
               dummy[subi][subj] = m[i][j];
               subj++;
            }
            subi++;
         }
         d = d + (pow(-1, x) * m[0][x] * det(dummy, n - 1 ));
      }
   }
   return d;
}
float detX(float a[max][max],int col,int n){
	float tmp[max][max];
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++)
		tmp[i][j] = a[i][j];
	}
	for(int i = 0 ; i < n ; i++){
		tmp[i][col] = a[i][n];
	}
	cout << "Thay B vao cot  thu " << col+1  << "  ta dc : "<< endl;
	print(tmp,n);       
	return det(tmp,n);
}
float* cramer(float a[max][max] ,int n){
	float detA = det(a,n);
	if(detA != 0){
		float d[4];
		float x[4];
		for(int i = 0 ; i < n ; i++){
			d[i] = detX(a,i,n);
			cout << "det = " << d[i] << endl;
			x[i] = d[i]/detA;
		} return x; 
}
}

// int Dinhthuc(int A[max][max], int n) 
// {
// 	int s, sum =0;
// 	if(n == 1) return A[0][0];
// 	if(n == 2) return A[0][0] * A[1][1] - A[0][1] * A[1][0];
// 	for(int k = 0; k < n ; k++) 
// 	{
// 		int B[max][max];
// 		for(int i = 0; i < n; i++) {
// 			for(int j = 1; j < n; j++) {
// 				if(i < k) B[i][j - 1] = A[i][j];
// 				if(i > k) B[i - 1][j-1] = A[i][j];
// 			}
// 		}
// 		if(k % 2 == 0) s = 1;
// 		else s = -1;
// 		sum += A[k][0] * s * Dinhthuc(B,n-1);
// 	}
// 	return sum;
// }

void menu()
{
    int c, n = 0, check = 0;
    float A[max][max],B[max][max], C[max];
    char file[max];
    FILE *f;
    do{
    cout << "******************MENU******************\n";
    cout << "*1. Nhap ma tran vao tu file           *\n";
    cout << "*2. Xuat ma tran ra man hinh           *\n";
    cout << "*3. Xuat ma tran ra file               *\n";
    cout << "*4. Tinh phuong phap guess jordan      *\n";
    cout << "*5. Tinh phuong phap cramer            *\n";
    cout << "*6. Tinh dinh thuc                     *\n";
    cout << "*7. Xoa man hinh                       *\n";
    cout << "*0. Thoat                              *\n";
    cout << "****************************************\n";
    cout << "Nhap lua chon cua ban: ";
    cin >> c;
    
    switch (c)
    {
    case 1: {
        cout << "Nhap duong dan file: ";
        cin >> file;
        check = Nhapmatran(A,n,file);
        if(check == 1)
        {
            cout << "Nhap ma tran thanh cong!\n";
        }
        break;
    }
    case 2: {
        if(check == 0)
        {
            cout << "Chon 1 de nhap ma tran tu file truoc!\n";
        }
        else
        {
        cout << "Ma tran vuong cap " << n << "\n";
        ScreenShow(A,n);
        }
        break;
    }
    case 3: {
        if(check == 0)
        {
            cout << "Chon 1 de nhap ma tran tu file truoc!\n";
        }
        else
        {
            cout << "Nhap duong dan file :" ;
            cin >> file;
            f = fopen(file, "w");
            if(f == NULL)
            {
                cout << "File error!\n";
            }
            else
            {
                Xuatmatran(A, n, f);
            }
        }
        break;
    }
    case 4: {
        if(check == 0)
        {
            cout << "Chon 1 de nhap ma tran tu file truoc!\n";
        }
        else
        {
            Gauss_Jordan(A,n,C);
            f = fopen("C.txt", "w");
            if(f == NULL)
            {
                cout << "File error!\n";
            }
            else
            {
                	GhiVaoFile(C,n,f);
            }
        
      
        }
        break;
    }
    case 5: {
        if(check == 0)
        {
            cout << "Chon 1 de nhap ma tran tu file truoc!\n";
        }
        else
        {
          float *r = cramer(A,n);
         
          for(int i = 0; i < n ; i++){
		   printf("x%d = %0.3f \t",i,r[i]);
		//cout << "Nhap duong dan file :" ;
            //cin >> file;
	}
	for(int i = 0 ; i < n ; i++){
		C[i] = r[i];
	}
	 f = fopen("B.txt", "w");
            if(f == NULL)
            {
                cout << "File error!\n";
            }
            else
            {
                	GhiVaoFile(C,n,f);
            }
        }
        break;
    }
    case 6: {
        if(check == 0)
        {
            cout << "Chon 1 de nhap ma tran tu file truoc!\n";
        }
        else
        {
            cout << "Det: "<<det(A,n)<< endl;
        }
        break;
    }
    case 7: {
        system("cls");
        break;
    }
    default: {
        exit(0);
        break;
    }
    }
    system("pause");
    }while (c < 8 && c!=0);
}
int main()
{
    menu();
}
