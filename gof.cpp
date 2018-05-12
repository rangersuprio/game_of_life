
//conway's game of life simulation
#include<iostream>
#include<cstdio>
#define c 10
int configure_grid(int grid[][c],size_t n);
int show_grid(int grid[][c],size_t n);
int get_choice(int grid[][c],size_t n,int pos1,int pos2);
int iterate(int grid[][c],size_t n);
int check_neighbours(int grid[][c],size_t n,int p1,int p2);

int main(void){
    size_t n;
    
    printf("Enter grid size: ");
    std::cin >> n;

    
        
    int pos1,pos2;
    int grid[n][c];
    configure_grid(grid,n);
    show_grid(grid,n);
    int t;
    printf("\nHow many choices: ");
    scanf("%d",&t);
    while(t--){
        printf("Enter grid position: ");
        std::cin >> pos1;
        std::cin >> pos2;
        get_choice(grid,n,pos1,pos2);
    }
    int limit;

    printf("\nHow long do you want to iterate: ");
    std::cin >> limit;
    for(int i=1;i<=limit;i++){
        iterate(grid,n);
        printf("\nIteration: %d\n",i);
        show_grid(grid,n);
    }


}
int configure_grid(int grid[][c],size_t n){
    size_t i,j;
    for(i=0;i<n;i++){
        for(j=0;j<c;j++){
            grid[i][j]=0;
        }
    }
}

int show_grid(int grid[][c],size_t  n){
    size_t i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<c;j++){
        
            printf("%5d",grid[i][j]);
        }
    }
}

int get_choice(int grid[][c],size_t  n,int pos1,int pos2){
    grid[pos1][pos2]=1;
}
int iterate(int grid[][c],size_t n){
    size_t i,j;

    for(i=0;i<n;i++){
        for(j=0;j<c;j++){
            if(check_neighbours(grid,n,i,j)>2) grid[i][j]=0;
            else if(check_neighbours(grid,n,i,j)==2) grid[i][j]=1;
            else if(check_neighbours(grid,n,i,j)>3) grid[i][j]=0;
        }
    }
}
int check_neighbours(int arr[][c],size_t n,int p1,int p2){
    size_t i,j;
    int count=0;
    
    if(arr[p1+1][p2+1]==1){
        count++;

    }
    if(arr[p1-1][p2-1]==1){
        count++;
    }

    if(arr[p1][p2+1]==1){
        count++;
    } 
    if(arr[p1][p2-1]==1){
        count++;
    }
    if(arr[p1-1][p2]==1){
        count++;
    }
    if(arr[p1+1][p2]==1){
        count++;
    }

    
    return count;
}
