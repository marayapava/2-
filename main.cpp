#include <iostream>

using namespace std;
/*
class vector3d
{
protected:
    int n;
    double *data = NULL;
public:
    vector3d(int n)
    {
        this->n = n;
        data = new double[n];
    }
    ~vector3d()
    {
        delete[]data;
    }
    vector3d operator+(const vector3d &vec)//�������� ��������
    {
        vector3d newvec(n);
        for(int i = 0; i < n; i++)
        {
            newvec.data[i] = vec.data[i] + data[i];
        }
        return newvec;
    }
    vector3d operator-(const vector3d &vec)//��������� ��������
    {
        vector3d newvec(n);
        for(int i = 0; i < n; i++)
        {
            newvec.data[i] = vec.data[i] - data[i];
        }
        return newvec;
    }
    vector3d operator*(double num) const//��������� �� ���������
    {
        vector3d newvec(n);
        for (int i = 0; i < n; i++)
        {
            newvec.data[i] = this->data[i]*num;
        }
        return newvec;
    }
    vector3d operator*(const vector3d &vec)// ��������� ������������
    {
        vector3d newvec(n);
        for(int i = 0; i < n; i++)
        {
            newvec.data[i] = vec.data[i]*data[i];
        }
        return newvec;
    }
    int getvalue(int i) const
    {
        return data[i];
    }
    void setvalue(int i, double value)
    {
        data[i] = value;
    }
};
vector3d operator*(int num, const vector3d &vec)// ��������� �� ���������
{
    return vec*num;
}
*/

class matrix
{
protected:
    int m;
    double *mat = NULL;
public:
    matrix(int m)
    {
        this->m = m;
        mat = new double[m];
    }
    ~matrix()
    {
        delete[]mat;
    }
    matrix operator+(const matrix &matrix_1)//�������� ��������
    {
        matrix newm(m);
        for(int i = 0; i < m; i++)
            {
                newm.mat[i] = matrix_1.mat[i] + mat[i];
            }
        return newm;
    }
    matrix operator*(const matrix &matrix_1)//�������� ��������
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
    matrix operator-(const matrix &matrix_1)//�������� ��������
    {
        matrix newm(m);
        for(int i = 0; i < m; i++)
            {
                newm.mat[i] = matrix_1.mat[i] - mat[i];
            }
        return newm;
    }
    matrix operator*(double num) const//��������� �� ���������
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
        det = mat[4]*mat[5]*mat[9] + mat[2]*mat[6]*mat[7] + mat[3]*mat[4]*mat[8] - mat[1]*mat[6]*mat[8] - mat[2]*mat[4]*mat[9] - mat[3]*mat[5]*mat[7];
        return det;
    }
};
matrix operator*(int num, const matrix &matrix_1)// ��������� �� ���������
{
    return matrix_1*num;
}



int main()
{
    setlocale(LC_ALL, "rus");
    /*int vector_value = 0;
    cout<<"������ ������"<<endl;
    vector3d a(3);
    for (int k = 0; k < 3; k++)
    {
        cin>>vector_value;
        a.setvalue(k,vector_value);
    }
    cout<<"������ ������"<<endl;
    vector3d b(3);
    for (int k = 0; k < 3; k++)
    {
        cin>>vector_value;
        b.setvalue(k,vector_value);
    }
    cout<<"����� ��������"<<endl;
    vector3d c = a + b;
    for (int k = 0; k < 3; k++)
    {
        cout<<c.getvalue(k)<<endl;
    }
    cout<<"�������� ��������"<<endl;
    vector3d d = a - b;
    for (int k = 0; k < 3; k++)
    {
        cout<<d.getvalue(k)<<endl;
    }
    cout<<"������ ������, ���������� �� 4"<<endl;
    vector3d e = 4*a;
    for (int k = 0; k < 3; k++)
    {
        cout<<e.getvalue(k)<<endl;
    }
    cout<<"��������� ������������"<<endl;
    vector3d f = b*a;
    for (int k = 0; k < 3; k++)
    {
        cout<<f.getvalue(k)<<endl;
    }*/
    double matrix_value;
    matrix a_1(9);
    cout<<"�������� ������ �������"<<endl;
    for(int j = 0; j < 9; j++)
    {
        cin>>matrix_value;
        a_1.setvalue(j,matrix_value);
    }
    matrix a_2(9);
    cout<<"�������� ������ �������"<<endl;
    for(int j = 0; j < 9; j++)
    {
        cin>>matrix_value;
        a_2.setvalue(j,matrix_value);
    }
    matrix a_sum = a_1 + a_2;
    cout<<"����� ������"<<endl;
    for(int j = 0; j < 9; j++)
    {
        if ((j + 1) % 3 != 0)
            cout<<a_sum.getvalue(j)<<"\t";
        else
            cout<<a_sum.getvalue(j)<<"\n";
    }
    matrix a_sub = a_1 - a_2;
    cout<<"�������� ������"<<endl;
    for(int j = 0; j < 9; j++)
    {
        if ((j + 1) % 3 != 0)
            cout<<a_sub.getvalue(j)<<"\t";
        else
            cout<<a_sub.getvalue(j)<<"\n";
    }
    matrix a_const = a_1 * 5;
    cout<<"������ �������, ���������� �� ����� 5"<<endl;
    for(int j = 0; j < 9; j++)
    {
        if ((j + 1) % 3 != 0)
            cout<<a_const.getvalue(j)<<"\t";
        else
            cout<<a_const.getvalue(j)<<"\n";
    }
    matrix a_multi = a_1 * a_2;
    cout<<"������������ ������"<<endl;
    for(int j = 0; j < 9; j++)
    {
        if ((j + 1) % 3 != 0)
            cout<<a_multi.getvalue(j)<<"\t";
        else
            cout<<a_multi.getvalue(j)<<"\n";
    }
    cout<<"����������� ������ �������"<<endl;
    cout<<a_1.determ()<<endl;
    return 0;
}
