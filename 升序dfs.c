void dfs(int m, int sum, int startx){//最重要的递归
//m代表现在选择了多少个数
//sum表示当前的和
//startx表示升序排列，以免算重
    if(m == k){//如果选完了的话
        if(isprime(sum))//如果和是素数
            ans++;//ans加一
        return ;
    }
    for(int i = startx; i < n; i++)
        dfs(m + 1, sum + a[i], i + 1);//递归
        //步数要加一，和也要加
        //升序起始值要变成i+1,以免算重
    return ;//这一个步骤下，所有的都枚举完了
    //直接返回去
}