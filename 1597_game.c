#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int fib[20];
int n;

void fibonachi(void){
    int i;
    fib[0]=1;
    fib[1]=1;
    for(i = 2 ; i < 20 ; i++){
        fib[i] = fib[i-1] + fib[i-2];
    }
}

int check_fib(int adad1 , int adad2){
    int i , k , j;
    for(i = 0 ; i < 20 ; i++){
        if(fib[i] == adad1){
            k = i;
            break;
        }
    }
    for(i = 1 ; i < 20 ; i++)
        if(fib[i] == adad2)
            j = i;
    if(k==0&&j==2)
        return 1;
    if((k - j) == 1 || (j - k) == 1)
        return 1;
    return 0;
}

void random(int a[n][n]){
    int i , j , k = 0 , counter = 0;
    for(i = 0 ; i < n ; i++){
        for(j = 0 ; j < n ; j++){
            if(a[i][j] == 0)
                counter++;
        }
    }
    if(counter == 0){
    }
    else{
        int *arr_pointers[counter];
        for(i = 0 ; i < n ; i++){
            for(j = 0 ; j < n ; j++){
                if(a[i][j] == 0){
                    arr_pointers[k] = &a[i][j];
                    k++;
                }
            }
        }
        time_t t = time(NULL);
        srand(t);
        int r = rand()%(k);
        *arr_pointers[r] = 1;
    }
}

int lose(int b[n][n]){
    int i , j , k , g = 0 , check;
    for(i = 0 ; i < n  ; i++){
        for(j = 0 ; j < n ; j++){
            if(b[i][j] > 0){
                for(k = i+1 ; k < n ; k++){
                    if(b[k][j] > 0){
                        check = check_fib(b[i][j] , b[k][j]);
                        if(check == 1){
                            g++;
                        }
                    break;
                    }
                }
            }
        }
    }
    for(i = (n-1) ; i >= 0 ; i--){
        for(j = (n-1) ; j >= 0 ; j--){
            if(b[i][j] != 0){
                for(k = (i-1) ; k >= 0 ; k--){
                    if(b[k][j] > 0){
                        check = check_fib(b[i][j] , b[k][j]);
                        if(check == 1){
                            g++;
                        }
                    break;
                    }
                }
            }
        }
    }
    for(j = 0 ; j < n ; j++){
        for(i = (n-1) ; i >=0 ; i--){
            if(b[i][j] != 0){
                for(k = (j+1) ; k < n ; k++){
                    if(b[i][k] > 0){
                        check = check_fib(b[i][j] , b[i][k]);
                        if(check == 1){
                            g++;
                        }
                    break;
                    }
                }
            }
        }
    }
    for(j = (n-1) ; j >= 0 ; j--){
        for(i = 0 ; i < n ; i++){
            if(b[i][j] != 0){
                for(k = (j-1) ; k >= 0 ; k--){
                    if(b[i][k] > 0){
                        check = check_fib(b[i][j] , b[i][k]);
                        if(check == 1){
                            g++;
                        }
                    break;
                    }
                }
            }
        }
    }
    if(g == 0){
        printf("you lost!");
        return 0;
    }
    return 1;
}

int jahat(int b[n][n] , int arr_undo[n][n]){
    int i , j , k , check ;
    char a ;
    a = getch();
    if(a == -32){
        switch(getch()){
            case 'H':
                for(i = 0 ; i < n ; i++){
                    for(j = 0 ; j < n ; j++){
                        arr_undo[i][j] = b[i][j];
                    }
                }
                for(i = 0 ; i < n  ; i++){
                    for(j = 0 ; j < n ; j++){
                        if(b[i][j] > 0){
                            for(k = i+1 ; k < n ; k++){
                                if(b[k][j] > 0){
                                    check = check_fib(b[i][j] , b[k][j]);
                                    if(check == 1){
                                        b[i][j] = b[i][j] + b[k][j];
                                        b[k][j] = 0;
                                    }
                                break;
                                }
                            }
                        }
                    }
                }
                for(i = 0 ; i < n ; i++){
                    for(j = 0 ; j < n ; j++){
                        if(b[i][j] == 0){
                            for(k = i+1 ; k < n ; k++){
                                if(b[k][j] != 0){
                                    b[i][j] = b[k][j];
                                    b[k][j] = 0;
                                    break;
                                }
                            }
                        }
                    }
                }
                random(b);
                break;


            case 'P':
                for(i = 0 ; i < n ; i++){
                    for(j = 0 ; j < n ; j++){
                        arr_undo[i][j] = b[i][j];
                    }
                }
                for(i = (n-1) ; i >= 0 ; i--){
                    for(j = (n-1) ; j >= 0 ; j--){
                        if(b[i][j] != 0){
                            for(k = (i-1) ; k >= 0 ; k--){
                                if(b[k][j] > 0){
                                    check = check_fib(b[i][j] , b[k][j]);
                                    if(check == 1){
                                        b[i][j] = b[i][j] + b[k][j];
                                        b[k][j] = 0;
                                    }
                                break;
                                }
                            }
                        }
                    }
                }
                for(i = (n-1) ; i >= 0 ; i--){
                    for(j = (n-1) ; j >= 0 ; j--){
                        if(b[i][j] == 0){
                            for(k = (i-1) ; k >= 0 ; k--){
                                if(b[k][j] != 0){
                                    b[i][j] = b[k][j];
                                    b[k][j] = 0;
                                    break;
                                }
                            }
                        }
                    }
                }
                random(b);
                break;

            case 'K':
                for(i = 0 ; i < n ; i++){
                    for(j = 0 ; j < n ; j++){
                        arr_undo[i][j] = b[i][j];
                    }
                }
                for(j = 0 ; j < n ; j++){
                    for(i = (n-1) ; i >=0 ; i--){
                        if(b[i][j] != 0){
                            for(k = (j+1) ; k < n ; k++){
                                if(b[i][k] > 0){
                                    check = check_fib(b[i][j] , b[i][k]);
                                    if(check == 1){
                                        b[i][j] = b[i][j] + b[i][k];
                                        b[i][k] = 0;
                                    }
                                break;
                                }
                            }
                        }
                    }
                }
                for(j = 0 ; j < n ; j++){
                    for(i = (n-1) ; i >=0 ; i--){
                        if(b[i][j] == 0){
                            for(k = (j+1) ; k < n ; k++){
                                if(b[i][k] != 0){
                                    b[i][j] = b[i][k];
                                    b[i][k] = 0;
                                    break;
                                }
                            }
                        }
                    }
                }
                random(b);
                break;

            case 'M':
                for(i = 0 ; i < n ; i++){
                    for(j = 0 ; j < n ; j++){
                        arr_undo[i][j] = b[i][j];
                    }
                }
                for(j = (n-1) ; j >= 0 ; j--){
                    for(i = 0 ; i < n ; i++){
                        if(b[i][j] != 0){
                            for(k = (j-1) ; k >= 0 ; k--){
                                if(b[i][k] > 0){
                                    check = check_fib(b[i][j] , b[i][k]);
                                    if(check == 1){
                                        b[i][j] = b[i][j] + b[i][k];
                                        b[i][k] = 0;
                                    }
                                break;
                                }
                            }
                        }
                    }
                }
                for(j = (n-1) ; j >= 0 ; j--){
                    for(i = 0 ; i < n ; i++){
                        if(b[i][j] == 0){
                            for(k = (j-1) ; k >= 0 ; k--){
                                if(b[i][k] != 0){
                                    b[i][j] = b[i][k];
                                    b[i][k] = 0;
                                    break;
                                }
                            }
                        }
                    }
                }
                random(b);
                break;
        }
    }
    else{
        if(a == 113){
            return 0;

        }
        else{
            if(a == 117){
                for(i = 0 ; i < n ; i++){
                    for(j = 0 ; j < n ; j++){
                        b[i][j] = arr_undo[i][j];
                    }
                }
            }
        }
    }
}


int end(int a[n][n]){
    int i , j , k = 0;
    for(i = 0 ; i < n ; i++){
        for(j = 0 ; j < n ; j++){
            if(a[i][j] > 0)
                k++;
            if(a[i][j] == 1597){
                printf("you won!");
                return 0;
            }
        }
    }
    if(k == n*n)
    {
        return lose(a);
    }
    return 1;
}

int main()
{
    printf("please enter n:");
    scanf("%d" , &n);
    if(n > 8 || n < 4)
        return -1;
    fibonachi();
    int a[n][n] , i , j , x , arr_undo[n][n];
    for(i = 0 ; i < n ; i++){
        for(j = 0 ; j < n ; j++){
            a[i][j] = 0;
        }
    }
    random(a);
    random(a);
    while(end(a) == 1){
        system("cls");
        for(i = 0 ; i < n ; i++){
            printf("\n\n");
            for(j = 0 ; j < n ; j++){
                printf("%5d" , a[i][j]);
            }
        }
        printf("\n");
        x = jahat(a , arr_undo);
        if(x == 0)
            return 0;
    }


    return 0;
}
