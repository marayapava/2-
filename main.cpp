#include <iostream>
#include <math.h>

using namespace std;

class vector3d
{
protected:
    int n;
    double *data = NULL;
    int m;
    double *mat = NULL;
public:
    vector3d(int n)
    {
        this->n = n;
        data = new double[n];
        this->m = m;
        mat = new double[m];
    }
    ~vector3d()
    {
        delete[]data;
        delete[]mat;
    }
    /*vector3d operator+(const vector3d &vec)//сложение векторов
    {
        vector3d newvec(n);
        for(int i = 0; i < n; i++)
        {
            newvec.data[i] = vec.data[i] + data[i];
        }
        return newvec;
    }
    vector3d operator-(const vector3d &vec)//вычитание векторов
    {
        vector3d newvec(n);
        for(int i = 0; i < n; i++)
        {
            newvec.data[i] = vec.data[i] - data[i];
        }
        return newvec;
    }
    vector3d operator*(double num) const//умножение на константу
    {
        vector3d newvec(n);
        for (int i = 0; i < n; i++)
        {
            newvec.data[i] = this->data[i]*num;
        }
        return newvec;
    }
    vector3d operator*(const vector3d &vec)// скалярное произведение
    {
        vector3d newvec(n);
        newvec = (sqrt(vec.data[0] * vec.data[0] + vec.data[1] * vec.data[1] + vec.data[2] * vec.data[2])) * (sqrt(data[0] * data[0] + data[1] * data[1] + data[2] * data[2]));
        return newvec;
    }*/
    vector3d operator*()//ошибка
    {
        vector3d new_vec(n);
        for(int i = 0; i < n; i++)
        {
            new_vec.data[i] = 0;
            for(int j = i; j < i + 3; j++)
                new_vec.data[i] = new_vec.data[i] + data[i] * mat[j];
        }
        return new_vec;
    }
    int getvalue(int i) const
    {
        return data[i];
    }
    void setvalue(int i, double value)
    {
        data[i] = value;
    }
};/*
vector3d operator*(int num, const vector3d &vec)// умножение на константу
{
    return vec*num;
}
*/

class matrix
{
protected:
    int m;
    double *mat = NULL;
    int n;
    double *data = NULL;
public:
    matrix(int m)
    {
        this->m = m;
        mat = new double[m];
        this->n = n;
        data = new double[n];
    }
    ~matrix()
    {
        delete[]mat;
        delete[]data;
    }
    matrix operator+(const matrix &matrix_1)//сложение векторов
    {
        matrix newm(m);
        for(int i = 0; i < m; i++)
            {
                newm.mat[i] = matrix_1.mat[i] + mat[i];
            }
        return newm;
    }
    matrix operator*(const matrix &matrix_1)//сложение векторов
    {
        matrix newm(m);
        double s = 0;
        int f = 0;
        int l = 0;
        int q = 0;
        int h = 0;
        for(int i = 0; i < 3; i++)
        {
            for(int j = l; j < l + 3; j++)
            {
                for(int k = f; k < f + 3; k++)
                {
                    s = s + mat[k] * matrix_1.mat[h];
                    h = h + 3;
                }
                newm.mat[j] = s;
                s = 0;
                q = q + 1;
                h = q;
            }
            l = l + 3;
            h = 0;
            q = 0;
            f = f + 3;
        }
        return newm;
    }
    matrix operator-(const matrix &matrix_1)//сложение векторов
    {
        matrix newm(m);
        for(int i = 0; i < m; i++)
            {
                newm.mat[i] = matrix_1.mat[i] - mat[i];
            }
        return newm;
    }
    matrix operator*(double num) const//умножение на константу
    {
        matrix newm(m);
        for (int i = 0; i < m; i++)
        {
            newm.mat[i] = this->mat[i]*num;
        }
        return newm;
    }
    int getvalue(int i) const
    {
        return mat[i];
    }
    void setvalue(int i, double value)
    {
        mat[i] = value;
    }
    double determ()
    {
        double det;
        det = mat[0]*mat[4]*mat[8] + mat[1]*mat[5]*mat[6] + mat[2]*mat[3]*mat[7] - mat[0]*mat[5]*mat[7] - mat[1]*mat[3]*mat[8] - mat[2]*mat[4]*mat[6];
        return det;
    }
};
matrix operator*(int num, const matrix &matrix_1)// умножение на константу
{
    return matrix_1*num;
}


int main()
{
    setlocale(LC_ALL, "rus");
    /*double number = 0.5;
    int vector_value = 0;
    cout<<"первый вектор"<<endl;
    vector3d a(3);
    for (int k = 0; k < 3; k++)
    {
        cin>>vector_value;
        a.setvalue(k,vector_value);
    }
    cout<<"второй вектор"<<endl;
    vector3d b(3);
    for (int k = 0; k < 3; k++)
    {
        cin>>vector_value;
        b.setvalue(k,vector_value);
    }
    cout<<"сумма векторов"<<endl;
    vector3d c = a + b;
    for (int k = 0; k < 3; k++)
    {
        cout<<c.getvalue(k)<<endl;
    }
    cout<<"разность векторов"<<endl;
    vector3d d = a - b;
    for (int k = 0; k < 3; k++)
    {
        cout<<d.getvalue(k)<<endl;
    }
    cout<<"первый вектор, умноженный на 4"<<endl;
    vector3d e = 4*a;
    for (int k = 0; k < 3; k++)
    {
        cout<<e.getvalue(k)<<endl;
    }
    cout<<"скалярное произведение первого и второго вектора, угол между которыми 60 градусов"<<endl;
    vector3d f = a * b * number;
    for (int k = 0; k < 3; k++)
    {
        cout<<f.getvalue(k)<<endl;
    }*/
    double matrix_value;
    matrix a_1(9);
    cout<<"элементы первой матрицы"<<endl;
    for(int j = 0; j < 9; j++)
    {
        cin>>matrix_value;
        a_1.setvalue(j,matrix_value);
    }
    matrix a_2(9);
    cout<<"элементы второй матрицы"<<endl;
    for(int j = 0; j < 9; j++)
    {
        cin>>matrix_value;
        a_2.setvalue(j,matrix_value);
    }
    vector3d a_vec(3);
    cout<<"вектор"<<endl;
    for(int j = 0; j < 3; j++)
    {
        cin >> matrix_value;
        a_vec.setvalue(j, matrix_value);
    }
    matrix a_sum = a_1 + a_2;
    cout<<"сумма матриц"<<endl;
    for(int j = 0; j < 9; j++)
    {
        if ((j + 1) % 3 != 0)
            cout<<a_sum.getvalue(j)<<"\t";
        else
            cout<<a_sum.getvalue(j)<<"\n";
    }
    matrix a_sub = a_1 - a_2;
    cout<<"разность матриц"<<endl;
    for(int j = 0; j < 9; j++)
    {
        if ((j + 1) % 3 != 0)
            cout<<a_sub.getvalue(j)<<"\t";
        else
            cout<<a_sub.getvalue(j)<<"\n";
    }
    matrix a_const = a_1 * 5;
    cout<<"первая матрица, умноженная на число 5"<<endl;
    for(int j = 0; j < 9; j++)
    {
        if ((j + 1) % 3 != 0)
            cout<<a_const.getvalue(j)<<"\t";
        else
            cout<<a_const.getvalue(j)<<"\n";
    }
    matrix a_multi = a_1 * a_2;
    cout<<"произведение матриц"<<endl;
    for(int j = 0; j < 9; j++)
    {
        if ((j + 1) % 3 != 0)
            cout<<a_multi.getvalue(j)<<"\t";
        else
            cout<<a_multi.getvalue(j)<<"\n";
    }
    vector3d a_v = a_1 * a_vec;
    cout<<"умножение вектора на первую матрицу"<<endl;
    for(int j = 0; j < 3; j++)
    {
            cout<<a_v.getvalue(j)<<"\t";
    }
    cout<<"детерминант первой матрицы"<<endl;
    cout<<a_1.determ()<<endl;
    return 0;
}
