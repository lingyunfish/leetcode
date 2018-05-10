//确定的点的子节点虽然有两个方向，但是确定点的父节点只会有一个
//使用取余方法，快速降低复杂度
class Solution {
    public:
        bool reachingPoints(int sx, int sy, int tx, int ty) {
            while (sx < tx && sy < ty) {
                if (tx > ty) tx %= ty;
                else ty %= tx;

            }
            if (sx == tx)
            {
                return (ty - sy) % tx ? false : true;

            }
            else if (sy == ty)
            {
                return (tx - sx) % ty ? false : true;

            }
            return false;

        }

};
