class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
            int rec1x1= rec1[0];
            int rec1y1= rec1[1];
            int rec1x2= rec1[2];
            int rec1y2= rec1[3];
            int rec2x1= rec2[0]; 
            int rec2y1= rec2[1];
            int rec2x2= rec2[2];
            int rec2y2= rec2[3];

           int x= min(rec1x2, rec2x2) -  max(rec1x1, rec2x1);
           int y= min(rec1y2, rec2y2) -  max(rec1y1, rec2y1);

           if(x>0 && y>0){
            return true;
           }
           else{
            return false;
           }
    }
};