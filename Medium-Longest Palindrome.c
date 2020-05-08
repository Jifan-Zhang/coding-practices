//Time consuming: beating 57%
//RAM consuming: beating 100%

char * longestPalindrome(char * a){
    if(*a=='\0' || *(a+1)=='\0'){
        return a;
    }
    char * p=a;
	int maxlen=0;
	static char s[1001];
    s[0]=a[0];s[1]='\0';
	for(int i=0;*(p+i+1)!='\0';i++){
		if(*(p+i)==*(p+i+1)){
			int tmpmax=2;
			int j=1;
			for(;j<=i;j++){
				if(*(p+i-j) == *(p+i+1+j))
					tmpmax=2+2*j;
				else
					break;
				}
			if(tmpmax>maxlen){
				maxlen=tmpmax;
				for(int m=0;m<maxlen;m++)
					s[m]=*(p+i-j+1+m);
					}
				s[maxlen]='\0';
			}
		
		if(*(p+i)==*(p+i+2)){
			int tmpmax=3;
			int j=1;
			for(;j<=i;j++){
				if(*(p+i-j) == *(p+i+2+j))
					tmpmax=3+2*j;
				else
					break;					
				}
			if(tmpmax>maxlen){
				maxlen=tmpmax;
				for(int m=0;m<maxlen;m++)
					s[m]=*(p+i-j+1+m);
					}
				s[maxlen]='\0';
			}
		}
	return s;
}
