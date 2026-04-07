//思路是，总体先按y轴排序，查找排雷火箭在雷中时二分，尽量剪枝
/*dfs伪代码
    idx = bisearch(ast.y);
    for(int i = idx; i >= 0 && abs(ast.y - pi.y) <= ast.r; i--){
        if(dist^2 <= r^2){
            cnt++;
            erase(pi);
        }
    }
    同样的for向正向做一遍cnt记录
*/