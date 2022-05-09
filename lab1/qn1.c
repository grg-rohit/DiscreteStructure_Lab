#include <stdio.h>
#include <conio.h>

int main(){
    int set1[20], set2[20], set3[20];
    int size1, size2;
    printf("Enter the size of first set: ");
    scanf("%d", &size1);
    printf("Enter the size of second set: ");
    scanf("%d", &size2);

    printf("Enter the elements of first set: \n");
    getSet(set1, size1);

    printf("Enter the elements of second set: \n");
    getSet(set2, size2);
	
	printf("Elements of First set: ");
    dispSet(set1, size1);
    
    printf("\n");
    printf("Elements of Second set: ");
    dispSet(set2, size2);
    printf("\n");
    Union(set1, set2, set3, size1, size2);
    printf("\n");
    
    Intersection(set1, set2, set3, size1, size2);
    printf("\n");
    
    printf("For A-B: \n");
    setDiff(set1, set2, set3, size1, size2);
    printf("\n");
    
    printf("For B-A: \n");
    setDiff(set2, set1, set3, size2, size1);
    printf("\n");
    
    symDiff(set1, set2, set3, size1, size2);
    printf("\n");
    
    return 0;
}

int getSet(int Set[20], int n){
    int i;
    for(i=0; i<n; i++){
        scanf("%d", &Set[i]);
    }
}

int dispSet(int Set[20], int n){
    int i;
	for(i=0; i<n; i++){
        printf("%d ", Set[i]);
    }

}

int Union(int setA[20], int setB[0], int setC[20], int n, int n1 ){
    int i, j, k;
    k=0;
    for(i=0; i<n; i++){
		for(j=0; j<k; j++){
			if(setC[j]==setA[i]) 
            break;
		}
		if(j==k){
          setC[k]=setA[i];
          k++;
       }
    }
    for(i=0; i<n1; i++){
		for(j=0; j<k; j++){
			if(setC[j]==setB[i]) 
            break;
		}
		if(j==k){
          setC[k]=setB[i];
          k++;
       }
    }
    printf("Union of First and Second set is: ");
    for(i=0;i<k;i++){
    	printf("%d ", setC[i]);
	}
}

int Intersection(int a[20], int b[0], int c[20], int n, int n1){
	int i,j,k;
	k=0;
	for(i=0; i<n; i++){
		for(j=0; j<n1; j++){
			if(a[i]==b[j]){
				c[k] = a[i];
				k++;
			}
		}
	}
	printf("Intersection of First and Second set is: ");
    for(i=0;i<k;i++){
    	printf("%d ", c[i]);    
	}
}

int setDiff(int a[20], int b[0], int c[20], int n, int n1){
	int i, j, k, l;
	k=0;
	for(i=0; i<n; i++){
		for(j=0; j<n1; j++){
			if(b[j]==a[i])
             break;
		}
		if(j==n1){
            for(l=0;l<k;l++)
            {
                if(c[l]==a[i])
                 break;
            }
            if(l==k)
            {
                c[k]=a[i];
                k++;
            }
        }
	}

    printf("Set Difference of sets is: ");
    for(i=0;i<k;i++){
    	printf("%d ", c[i]);
	}
}

int symDiff(int a[20], int b[0], int c[20], int n1, int n2){
	int i, j, k, l, m, n;
	int d[20], e[20];
	k=0; 
	m=0; 
	n=0;
	for( i=0;i<n1;i++){
       
        for(j=0;j<n2;j++)
        {
            if(b[j]==a[i])
             break;
        }
        if(j==n2)
        {
            
            for(l=0;l<k;l++)
            {
                if(d[l]==a[i])
                 break;
            }
            if(l==k)
            {
                d[k]=a[i];
                k++;
            }
        }
        
    }
    
    // logic for find B-A
    
    for( i=0;i<n2;i++)
    {
        for(j=0;j<n1;j++)
        {
            if(b[i]==a[j])
             break;
        }
        if(j==n1)
        {
            for(l=0;l<m;l++)
            {
                if(d[l]==b[i])
                 break;
            }
            if(l==m)
            {
                e[m]=b[i];
                m++;
            }
        }
        
    }
    
    for(i=0;i<k;i++)
    {
        c[n]=d[i];
        n++;
    }
    for(i=0;i<m;i++)
    {
        c[n]=e[i];
        n++;
    }

	
    printf("Symmetric Difference of sets is: ");
    for(i=0;i<n;i++){
    	printf("%d ", c[i]);
	}
}
