void build(int l,int h,int ind,int a[],int seg[])
{
    if(l==h)
    {
        //cout<<l<<" "<<a[l]<<endl;
        seg[ind]=a[l];
        return;
        
    }
    int m=(l+h)/2;
    build(l,m,2*ind+1,a,seg);
    build(m+1,h,2*ind+2,a,seg);
   
    seg[ind]=seg[2*ind+1]+seg[2*ind+2];
   
    

}

          
int query(int l,int h,int low,int high,int ind,int seg[])
{
    if(l>high||h<low)
        return INT_MAX;
    if(l<=low&&h>=high)
        return seg[ind];
    int m=(low+high)/2;

    int x=query(l,h,low,m,2*ind+1,seg);
    int y=query(l,h,m+1,high,2*ind+2,seg);
    return x+y;
}

void update(int pt,int l,int h,int ind,int z,int seg[])
{
    if(l==h)
    {
        
        seg[ind]=z;
       
        return;
    }
    int m=(l+h)/2;
    if(m>=pt)
    {
        update(pt,l,m,2*ind+1,z,,seg);
    }
    else
    {
        update(pt,m+1,h,2*ind+2,z,seg);
    }
    
    seg[ind]=seg[2*ind+1]+seg[2*ind+2];
    
   
}