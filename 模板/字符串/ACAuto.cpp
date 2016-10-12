/* HDU2222 验过
    1. 数组用法
        len 长度 end 模式串终结符
        依据需要添加数组记录相应信息
    2. insert()
        依据数组修改，注意对应数组含义
    3. query()
        重点在改最内层的while循环
*/

struct ACAuto {
    const static int type = 26;
    int next[MAXN][type], fail[MAXN], end[MAXN], len[MAXN];
    int root, tot;
    int newnode() {
        for( int i = 0; i < type; ++i ) next[tot][i] = -1;
        len[tot] = 0; end[tot++] = -1;
        return tot - 1;
    }
    void init() {
        tot = 0;
        root = newnode();
    }
    void insert( char *s ) {
        int tlen = strlen( s ), u = root;
        for( int i = 0; i < tlen; ++i ) {
            int idx = s[i] - 'a';
            if( next[u][idx] == -1 ) next[u][idx] = newnode();
            u = next[u][idx];
        }
        end[u] = 1; len[u] = tlen;
    }
    void build() {
        queue<int> que;
        fail[root] = root;
        for( int i = 0; i < type; ++i ) {
            if( next[root][i] == -1 ) next[root][i] = root;
            else {
                fail[next[root][i]] = root;
                que.push( next[root][i] );
            }
        }
        while( !que.empty() ) {
            int u = que.front(); que.pop();
            for( int i = 0; i < type; ++i ) {
                if( next[u][i] == -1 ) next[u][i] = next[fail[u]][i];
                else {
                    fail[next[u][i]] = next[fail[u]][i];
                    que.push( next[u][i] );
                }
            }
        }
    }
    void query( char *s ) {
        int idx, tlen = strlen( s ), u = root;
        memset( pos, 0, sizeof pos );
        for( int i = 0; i < tlen; ++i ) {
            // 忽略大小写
            if( s[i] >= 'A' && s[i] <='Z' ) idx = s[i]-'A';
            else if( s[i] >= 'a' && s[i] <='z' ) idx = s[i]-'a';
            else continue;
            u = next[u][idx];
            int tp = u;
            while( tp != root ) {
                if( end[tp] != -1 ) {
                    pos[i + 1] -= 1;
                    pos[i - len[tp] + 1] += 1;
                    break;
                }
                tp = fail[tp];
            }
        }
        int cnt = 0;
        for( int i = 0; i < tlen; ++i ) {
            cnt += pos[i];
            if( cnt <= 0 ) putchar( s[i] );
            else putchar( '*' );
        }
        puts( "" );
    }
}AC;
