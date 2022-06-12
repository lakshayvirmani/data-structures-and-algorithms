class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<double> distances;
        vector<int> remaining;
        
        // Initialize. Precompute and store distances.
        double lo = 0, hi = 0;
        for(int i = 0; i < points.size(); i++)
        {
            distances.push_back(euclideanDistance(points[i]));
            hi = max(hi, distances[i]);
            remaining.push_back(i);
        }
        
        vector<int> closest;
        while(k)
        {
            double mid = lo + (hi - lo) / 2;
            
            vector<vector<int>> result = splitDistances(remaining, distances, mid);
            vector<int>& closer = result[0];
            vector<int>& farther = result[1];
            
            if(closer.size() > k)
            {
                hi = mid;
                remaining.swap(closer);
            }
            else
            {
                k -= closer.size();
                closest.insert(closest.end(), closer.begin(), closer.end());
                remaining.swap(farther);
                lo = mid;
            }
        }
        
        vector<vector<int>> answer;
        for(int idx : closest)
        {
            answer.push_back(points[idx]);
        }
        
        return answer;
    }
    
private:
    double euclideanDistance(vector<int> point)
    {
        return point[0] * point[0] + point[1] * point[1];
    }
    
    vector<vector<int>> splitDistances(vector<int>& remaining, vector<double>& distances, double mid)
    {
        vector<vector<int>> result (2);
        
        vector<int>& closer = result[0];
        vector<int>& farther = result[1];
        
        for(int idx : remaining)
        {
            if(distances[idx] <= mid)
            {
                closer.push_back(idx);
            }
            else
            {
                farther.push_back(idx);
            }
        }
        
        return result;
    }
};
