void sortAt(int p[],int at[],int bt[],int n)
{
      int i,j;
      for(i=0;i<n;i++)
      {
            for(j=i;j<n;j++)
            {
                  if(at[i]>at[j])
                  {
                        swap(&p[i],&p[j]);
                        swap(&at[i],&at[j]);
                        swap(&bt[i],&bt[j]);
                  }
                  else if(at[i]==at[j])
                  {
                        if(bt[i]>bt[j])
                        {
                              swap(&p[i],&p[j]);
                              swap(&at[i],&at[j]);
                              swap(&bt[i],&bt[j]);
                        }
                  }
            }
      }
}
