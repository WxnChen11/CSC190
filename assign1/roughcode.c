double **Ai;

initMatrix(&Ai,n-i);

Ai[0][0] = A[1][1];

for(x=0; x<n-i; x++){

for(y=0; y<n-i; y++){

VVT[x][y] = A[x+2][1] * A[1][y+2];

}

}


double **L;

initMatrix(&L,n);

int x,y;

double a = Ai[0][0];

for(x=0; x<n; x++){

L[x][x] = 1;
L[x][0] = A[x][0]/sqrt(a);

}

L[0][0] = sqrt(a);

double **B, **VVT;

initMatrix(&B, n);
initMatrix(&VVT, n);







for(x=1; x<n; x++){

	for(y=1; y<n; y++){
	
	B[x][y] = A[x][y]-(VVT[x][y]/a);

	}
}


return mult( L , choleskyDecomp(B, n, 0), n);
//return L;
//return B;

