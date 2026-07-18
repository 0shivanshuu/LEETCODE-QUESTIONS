class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int j=n-1;
        int i=0;
        int area=0;
        
       while(i<j){
        int b=j-i;
        int l=min(height[i],height[j]);

        area=max(area,b*l);

        if(height[i]<height[j]){

            i++;
        }
        else{
            j--;
        }
        
       }

       return area;

    }
};