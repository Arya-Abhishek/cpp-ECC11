void merge(int a[], int si,int mid, int ei)
{
   // int mid = (si+ei)/2;
    int i=si, j=mid+1, k=0;/////////////
    int temp[1000];
    while(i <= mid && j <= ei)
    {
        if(a[i] <= a[j]) {
            temp[k] = a[i];
            i++;
        }
        else {
            temp[k] = a[j];
            j++;
        }
        k++;
        
    }
    while(j <= ei)
    {
        temp[k] = a[j];
        j++;
        k++;
    }
    while(i <= mid)
    {
        temp[k] = a[i];
        i++;
        k++;
    }
    for(int x=si;x<=ei;x++)
    {
        a[x]=temp[x-si];
    }
}

void mergeSort(int input[], int si, int ei)
{
   
    if(ei<=si)
        return;
    int mid = (si+ei)/2;

    mergeSort(input, si, mid);
    mergeSort(input,mid+1, ei);
    merge(input, si, mid, ei);//as mid is the starting of second half of the aray
    
}

void mergeSort(int input[], int size)
{
     int ei = size-1;
    mergeSort(input,0,ei);
}


    