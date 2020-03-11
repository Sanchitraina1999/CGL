#include"iostream"
using namespace std;

class XMatrix{
private:
    float **matrix;
    int n;
public:
    XMatrix(int);
    XMatrix operator *(XMatrix&);
    XMatrix operator +(XMatrix&);
};
XMatrix::XMatrix(int n){
    this->n=n;
    matrix=new float* [n];
    for(int i=0;i<n;i++)
        matrix[i]=new float[3];
}
XMatrix XMatrix::operator *(XMatrix &m){

}
XMatrix XMatrix::operator +(XMatrix &m){

}
