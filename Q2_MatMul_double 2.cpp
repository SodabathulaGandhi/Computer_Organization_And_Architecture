#include<bits/stdc++.h>

using namespace std;

void mulMat(vector <vector<double> > &mat1,vector <vector<double> > &mat2) {
    int R1 = mat1.size(),C1=mat1[0].size(),R2=mat2.size(),C2=mat2[0].size();
    vector <vector<double> > rslt(R1,vector <double>(C2,0));
	cout << "Multiplication of given two matrices is:\n" << endl;

	for (int i = 0; i < R1; i++) {
		for (int j = 0; j < C2; j++) {
			rslt[i][j] = 0;

			for (int k = 0; k < R2; k++) {
				rslt[i][j] += mat1[i][k] * mat2[k][j];
			}

			cout << rslt[i][j] << "\t";
		}

		cout << endl;
	}
}

int main(void) {
    int N;
    cout<<"enter size: ";
    cin>>N;
    clock_t t;
    t = clock();
    int R1,C1,R2,C2;
    // cout<<"enter data R1";
	// cin>>R1;
    // cout<<"enter data C1";
    // cin>>C1;
    // cout<<"enter data R2";
    // cin>>R2;
    // cout<<"enter data C2";
    // cin>>C2;
    R1=N;
    C1=N;
    R2=N;
    C2=N;

	
	vector <vector<double> > mat1(R1,vector<double>(C1));
	vector <vector<double> > mat2(R2,vector<double>(C2));
	
	for(int i=0;i<R1;i++)
	    for(int j=0;j<C1;j++)
        {
            // cout<<"enter data for M1";
            // cin>>mat1[i][j];
            mat1[i][j]=rand ();
        }
	        
	
	for(int i=0;i<R2;i++)
	    for(int j=0;j<C2;j++)
        {
        //      cout<<"enter data for M2";
        //    cin>>mat2[i][j];
             mat2[i][j]=rand ();
        }
	        

	if (C1 != R2) {
		cout << "The number of columns in Matrix-1 must be equal to the number of rows in "
				"Matrix-2" << endl;
		cout << "Please update MACROs according to your array dimension in #define section"
				<< endl;

	    return 0;
	}
    t = clock();
    
	mulMat(mat1, mat2);
     t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
  
     printf("\nMatrix_multiplication took %f seconds to execute \n", time_taken);



	return 0;
}
