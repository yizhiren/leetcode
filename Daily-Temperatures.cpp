class Solution {
public:

    map<int, list<int>> makePlace(const vector<int>& T){
        map<int, list<int>> places;
        
        for(int i=0;i<T.size();i++){
            places[T[i]].push_back(i);
        }
        
        return places;
    }
    
    int findWarmer(int place, int temp, map<int, list<int>>& places){
        int minWarmerPlace = numeric_limits<int>::max();
        for(int i=temp+1;i<=100;i++){
            auto& tempPlaces = places[i];
            auto it =tempPlaces.begin();
            while(it!=tempPlaces.end()){
                if(*it < place){
                    tempPlaces.erase(it++);
                }else if(*it < minWarmerPlace){
                    minWarmerPlace = *it;
                    break;
                }else{
                    break;
                }
            }
        }
        return minWarmerPlace == numeric_limits<int>::max() ? place: minWarmerPlace;
    }
    vector<int> dailyTemperatures(vector<int>& T) {
        auto places = makePlace(T);
        vector<int> result(T.size());
        
        for(int i=0;i<result.size();i++){
            int p = findWarmer(i, T[i], places);
            result[i] = p-i;
        }
        
        return result;
    }
};
