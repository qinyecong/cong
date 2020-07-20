#include<stdio.h>
#define MAXVALUE 100000 
#define MAXBITS 128 

typedef struct
{ int weight,parent,lchild,rchild;
}HNodeType;

typedef struct
{ int bit[MAXBITS];
  int start;
}HCodeType;

 
void Create_HuffMTree(HNodeType HFMTree[ ],int num[ ],int n) 
{ int m1,x1,m2,x2,i,j;
  for(i=0;i<2*n-1;i++)
  { HFMTree[i].weight=0;
    HFMTree[i].parent=-1;
    HFMTree[i].lchild=HFMTree[i].rchild=-1;
  }
  for(i=0;i<n;i++)
    HFMTree[i].weight=num[i];
  for(i=0;i<n-1;i++)
  { x1=x2=MAXVALUE;
    m1=m2=0;
    for(j=0;j<n+i;j++)
    { if(HFMTree[j].parent==-1 && HFMTree[j].weight<x1)
      { x2=x1;m2=m1;
        x1=HFMTree[j].weight;m1=j;
      }
      else if(HFMTree[j].parent==-1 && HFMTree[j].weight<x2)
      { x2=HFMTree[j].weight;
        m2=j;
      }
    }
    HFMTree[m1].parent=HFMTree[m2].parent=n+i;
    HFMTree[n+i].weight=HFMTree[m1].weight+HFMTree[m2].weight;
    HFMTree[n+i].lchild=m1;HFMTree[n+i].rchild=m2;
  }
}

 
void HaffmanCode(HNodeType HFMTree[ ],HCodeType HuffCode[ ],int n)
{ HCodeType cd;
  int i,j,c,p;
  for(i=0;i<n;i++)
  { cd.start=MAXBITS-1; 
    c=i;
    p=HFMTree[c].parent;
    while(p!=-1)
    { if(HFMTree[p].lchild==c)cd.bit[cd.start]=0;
      else cd.bit[cd.start]=1;
      cd.start--;
      c=p;
      p=HFMTree[c].parent;
    }
    for(j=cd.start+1;j<MAXBITS;j++)  
      HuffCode[i].bit[j]=cd.bit[j];
    HuffCode[i].start=cd.start+1;
  }
}

 

void main()
{ HNodeType HFMTree[2*MAXBITS-1];
  HCodeType HuffCode[MAXBITS];
    int num[MAXBITS];
    char ch[MAXBITS];
  char c;
  int n,i;
  for(i=0;i<MAXBITS;i++)num[i]=0;
  n=0;
  char filename[81];
    FILE *fp;
    puts("请输入文本文件标识符");
    scanf("%s",filename);
    if(!(fp=fopen(filename,"r")))
    {
       puts("文件打不开！");
   }
    else while(fscanf(fp,"%c",&c)!=EOF)
    {
        { if(n<1)
        {    ch[n]=c; num[n++]=1;}
        else
        { for(i=0;i<n;i++)
                if(c==ch[i])break;
            if(i<n)
                num[i]++;
            else
            {    ch[n]=c; num[n++]=1;}
        }
    }
    }
    fclose(fp);
    puts("每个字符出现的次数为");
    for(i=0;i<n;i++)
        printf("%c:%d\n",ch[i],num[i]);
    Create_HuffMTree(HFMTree,num ,n);  
    HaffmanCode(HFMTree , HuffCode , n);
    puts("每个字符的哈夫曼编码为");
    for(i=0;i<n;i++)
    { int j;
      printf("%c: ",ch[i]);
        for(j=HuffCode[i].start;j<MAXBITS;j++)
            printf("%d",HuffCode[i].bit[j]);
         puts("");
    }
}
