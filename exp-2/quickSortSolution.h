int partition(int a[], int si, int ei)
{
    int x = a[si], c=0;
    for(int i = si+1; i <= ei; i++)
    {
        if(a[i] <= x)
            c++;
    }
    
    int temp;
    temp = a[si+c];
    a[si+c] = a[si];
    a[si] = temp;    //swapping the first found element so that it comes to its right place
    int i = si;     //to its right place and then we arrange the remaining elements on 
    int j = ei;     //right hand and left side as follows
    
    while(i <= si+c && j >=si+c)    //note here previously it was giving run time error 
    {                               //but now we restricted i and j
        if(a[i] <= a[si+c])
            i++;
        else if(a[j] > a[si+c])
            j--;
        else
        {
            int t = a[j];
            a[j] = a[i];
            a[i] = t;
            i++;
            j--;
        }
    }
   
    return si+c;
}
void quickSort(int input[], int si, int ei) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Change in the given array itself.
     Taking input and printing output is handled automatically.
  */
    if(si == ei || si > ei)
        return;
    int c = partition(input, si, ei);
    quickSort(input, si, c-1);
    quickSort(input, c+1, ei);
    

}
void quickSort(int input[], int size)
{
    int ei = size-1;
    quickSort(input, 0, ei);
}
