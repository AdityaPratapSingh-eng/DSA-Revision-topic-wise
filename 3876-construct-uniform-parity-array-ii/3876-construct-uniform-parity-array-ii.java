class Solution {
    public boolean uniformArray(int[] nums1) {
          int mn= nums1[0];
          for(int i=1; i<nums1.length; i++){
                mn= Math.min(mn, nums1[i]);
          }

          if(mn %2==1){
                return true;
          }
            for(int a: nums1){
                 if(a%2==1){
                    return false;
                 }
            }
            return true;
    }
}