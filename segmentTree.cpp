#include<bits/stdc++.h>
using namespace std;
#define float long double
#define deb(x) cout<<#x<<" -> "<<x<<"\n";
class SEGMENT_TREE
{
    public:
    int max_n;
    int inf;
    vector<int> seg_tree;
    SEGMENT_TREE(int n,vector<int> &A)
    {
        max_n=2e5+2;
        inf=1e9+200;
        seg_tree=vector<int> (4*max_n,inf);
        init(0,n-1,A,0);
    }
    
    
    void init(int s,int e,vector<int> &A,int i)
    {
        if(s>e) return;
        if(s==e)
        {
            seg_tree[i]=A[s];
            // cout<<s<<" "<<e<<" "<<seg_tree[i]<<endl;
            return;
        }
        int mid=(s+e)/2;
        init(s,mid,A,2*i+1);
        init(mid+1,e,A,2*i+2);    

        int Lchild=seg_tree[2*i+1];
        int Rchild=seg_tree[2*i+2];
        seg_tree[i]=min(Lchild,Rchild);
        // cout<<s<<" "<<e<<" "<<seg_tree[i]<<endl;
    }
    void update(int s,int e,int idx,int val,vector<int> &A,int i)
    {
        if(s>e) return;

        if(s==e && s==idx)
        {
            seg_tree[i]=val;
            return;
        }

        int mid=(s+e)/2;
        if(idx<=mid)
        {
            update(s,mid,idx,val,A,2*i+1);
        }
        else
        {
            update(mid+1,e,idx,val,A,2*i+2);
        }
        seg_tree[i]=min(seg_tree[2*i+1],seg_tree[2*i+2]);    
    }
    int query(int qL,int qR,int s,int e,vector<int> &A,int i)
    {
        if(qL<=s && e<=qR)
        {
            return seg_tree[i];
        }
        if(qR<s) return inf;
        if(e<qL) return inf;
        int mid=(s+e)/2;

        int Lchild=query(qL,qR,s,mid,A,2*i+1);
        int Rchild=query(qL,qR,mid+1,e,A,2*i+2);
        return min(Lchild,Rchild);

    }
    
};
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin>>n;
    int q; cin>>q;

    vector<int> A(n);
    for(int i=0;i<n;i++) cin>>A[i];
    init(0,n-1,A,0);
    for(int i=0;i<q;i++)
    {
        int type; cin>>type;
        if(type==1)
        {
            int idx,val; cin>>idx>>val;
            idx--;
            update(0,n-1,idx,val,A,0);
        }
        else
        {
            int qR,qL;
            cin>>qL>>qR;
            qL--;
            qR--;
            
            cout<<query(qL,qR,0,n-1,A,0)<<endl;
        }


    }




    return 0;
}
// IF YOU GET AN INTUITION OF A SOLUTION THINK MORE RATHER THAN IMPLEMENTING WITH USING UGLY DATA STRUCTURES
//  THINK BRUTE FORCEh
// THINK IN REVERSE PROCESS remember codeforces 714 reverse dp
// MAXIMING A MATHEMATICAL EXPRESSION, TRY SHUFFLING THE SIMILAR TERMS TOGETHER
// clear global vectors and arrays
// print auxiliary array maybe it is Monotonic hence bsearch can be applied
// LOOK FOR UPPER BOUNDS ON SOMETHING TO FIT INTO CONSTRAINTS
// in a bitwise question see if there is an upper bound after which ans is always yes or no
// factors can be computed in log n are precomputing seive
// in game theory questions work out some examples
// cout<<fixed<<setprecision(9)<<ans<<endl;
// if(gcd(a,b)=g) then consider a=A*g , b=B*g where A and B are coprime
// in a graph you can at times dfs over unvisited vertices
// iterate over odd and even lengths
// colin galen convex hull gives us max value
// max seg tree Cg, to update we need to add the extra value
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// class sum_t
// {

//   long long identity;

// public:
//   long long val;
//   sum_t()
//   {
//     identity = 0;
//     val = 0;
//   }
//   long long operation(long long a, long long b)
//   {
//     return a + b;
//   }
//   void replace(long long a)
//   {
//     // val+=a;
//     val = a;
//   }
// };
// template <typename num_t>
// class seg_tree
// {
//   vector<num_t> tree;

// public:
//   int n;
//   seg_tree(int N, vector<long long> &A)
//   {
//     n = N;
//     tree = vector<num_t>(4 * N, num_t());
//     init(0, n - 1, A, 0);
//   }
//   void init(int s, int e, vector<long long> &A, int i)
//   {
//     if (s == e)
//     {

//       tree[i].val = A[s];
//       // cout << s << " " << e << " " << tree[i].val << endl;
//       // cout << "i: " << i << endl;
//       return;
//     }
//     int mid = s + (e - s) / 2;
//     init(s, mid, A, 2 * i + 1);
//     init(mid + 1, e, A, 2 * i + 2);
//     tree[i].val = tree[i].operation(tree[2 * i + 1].val, tree[2 * i + 2].val);
//     // cout << s << " " << e << " " << tree[i].val << endl;
//     // cout << "i: " << i << endl;
//   }
//   void update(int idx, vector<long long> &A, long long upd, int i, int s, int e)
//   {
//     if (e < idx)
//       return;
//     if (s > idx)
//       return;
//     if (s == e)
//     {
//       assert(s == idx);
//       A[i] = upd;
//       tree[i].replace(A[i]);
//       return;
//     }
//     int mid = (s + e) / 2;
//     if(idx<=mid)
//     update(idx, A, upd, 2 * i + 1, s, mid);
//     else
//     update(idx, A, upd, 2 * i + 2, mid + 1, e);
//     tree[i].val = tree[i].operation(tree[2 * i + 1].val, tree[2 * i + 2].val);
//   }
  
//   long long query(int qL, int qR, vector<long long> &A, int i, int s, int e)
//   {
//     if (e < qL)
//       return num_t();
//     if (s > qR)
//       return num_t();
//     if (qL <= s && e <= qR)
//     {

//       // cout << s << " " << e << " " << tree[i].val << endl;
//       // cout << "i: " << i << endl;
//       return tree[i];
//     }
//     int mid = s + (e - s) / 2;
//     num_t Lchild = query(qL, qR, A, 2 * i + 1, s, mid);
//     num_t Rchild = query(qL, qR, A, 2 * i + 2, mid + 1, e);
//     num_t to_return;
//     to_return.val = to_return.operation(Lchild.val, Rchild.val);
//     // cout << s << " " << e << " " << tree[i].val << endl;
//     // cout << "i: " << i << endl;
//     return to_return;
//   }
// };
// signed main()
// {

//   int n;
//   cin >> n;
//   vector<long long> A(n);
//   int q;
//   cin >> q;
//   for (int i = 0; i < n; i++)
//     cin >> A[i];
//   seg_tree<sum_t> T(n, A);
//   // cout << endl
//   //      << endl;
//       // T.s();
//       //  return 0;
//   for (int i = 0; i < q; i++)
//   {
//     int type;
//     cin >> type;
//     if (type == 1)
//     {
//       int idx;
//       long long x;
//       cin >> idx >> x;
//       idx--;
//       T.update(idx,A,x,0,0,n-1);
//     }
//     else
//     {
//       int qL, qR;
//       cin >> qL >> qR;
//       qL--;
//       qR--;
//       // cout<<"yo ";
//       // cout<<qL<<" "<<qR<<endl;
//       cout << T.query(qL, qR, A, 0, 0, n - 1).val << endl;
//     }
//   }

//   // assuming that range queries update for sum means adding x in L.....R

//   // assuming that range queries update for min means changing L...R by x

//   // assuming that range queries update for max means changing L...R by x

//   // assuming that range queries update for gcd means multiplying L...R by x

//   return 0;
// }