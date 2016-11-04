#include <bits/stdc++.h>
using namespace std;
const int MAXN = 110;
const string sp = "    ";

struct Node {
    string s;
    int flag;  // 0: cat 1: bk
    vector<struct Node *> child;
} *root;
char line[MAXN];
int cnt, len;
string names[MAXN];

string getbknm( int &p1 ) {
    char ret[MAXN] = "";
    int p2 = p1, tlen = 0;
    while( line[p2] != '/' && p2 < len ) ++p2;
    while( p1 < p2 ) {
        ret[tlen] = line[p1];
        ++tlen; ++p1;
    }
    ++p1;
    return ret;
}

void build( Node *root, int dep ) {
    if( dep >= cnt ) return ;
    int tlen = root->child.size();
    for( int i = 0; i < tlen; ++i ) {
        if( root->child[i]->s == names[dep] && ( root->child[i]->flag ) == ( cnt - dep == 1 ) ) {
            build( root->child[i], dep + 1 );
            return ;
        }
    }
    Node *tnode = new Node();
    tnode->s = names[dep];
    tnode->flag = ( dep < cnt - 1 ) ? 0 : 1;
    root->child.push_back( tnode );
    build( tnode, dep + 1 );
    return ;
}

bool cmp( const Node *pa, const Node *pb ) {
    if( ( pa->flag ) == ( pb->flag ) ) return ( pa->s ) < ( pb->s );
    return ( pa->flag ) < ( pb->flag );
}

void print( Node *root, int dep ) {
    if( ~dep ) {
        for( int i = 0; i < dep; ++i ) printf( "%s", sp.c_str() );
        printf( "%s", root->s.c_str() );
        puts( "" );
    }
    sort( root->child.begin(), root->child.end(), cmp );
    int tlen = root->child.size();
    for( int i = 0; i < tlen; ++i ) print( root->child[i], dep + 1 );
    return ;
}

int main() {
    int ncas = 0;
    while( NULL != fgets( line, MAXN, stdin ) ) {
        printf( "Case %d:\n", ++ncas );
        if( !strcmp( line, "0\n" ) ) break;
        root = new Node();
        root->flag = true;
        do {
            int p1 = 0;
            len = strlen( line );
            string str;
            cnt = 0;
            line[--len] = 0;
            while( p1 < len ) names[cnt++] = getbknm( p1 );
            build( root, 0 );
        } while( NULL != fgets( line, MAXN, stdin ) && strcmp( line, "0\n" ) );
        print( root, -1 );
    }
    return 0;
}
