
#define DBG 0

#ifdef DBG
    #define PRINTF
#else
    #define PRINTF printf
#endif


class Solution {
    pair<int, int> prePointBak;
    
	pair<int, int> &getPreOne(list<pair<int, int> >::iterator &it){
		list<pair<int, int> >::iterator it_tmp = it;
		it_tmp--;
		return *it_tmp;
	}
	pair<int, int> &getNextOne(list<pair<int, int> >::iterator &it){
		list<pair<int, int> >::iterator it_tmp = it;
		it_tmp++;
		return *it_tmp;
	}
	void insertPoint(list<pair<int, int> > &skyline, list<pair<int, int> >::iterator it,int x, int y){
		pair<int,int> newpoint(x,y);
		prePointBak = getPreOne(it);
		skyline.insert(it,newpoint);
		PRINTF("inser[%d],[%d]\n",x,y);
	}
	void adjustHeight(list<pair<int, int> > &skyline,list<pair<int, int> >::iterator &it, int height) {
        pair<int, int> &preskypoint = getPreOne(it);
	    int preskypoint_y = preskypoint.second;	 
	    prePointBak=*it;
        if(preskypoint_y==height){
			list<pair<int, int> >::iterator it_tmp = it;
			
			it--;
			skyline.erase(it_tmp);
		}else{
			it->second=height;
		}
	}
public:
    vector<pair<int, int> > getSkyline(vector<vector<int> >& buildings) {
        vector<pair<int, int> > result;
        if(buildings.size()==0)return result;
        
        list<pair<int, int> > skyline;
        pair<int,int> virtual_first_point(INT_MIN,0);
        skyline.push_back(virtual_first_point);
        pair<int,int> virtual_last_point(INT_MAX,0);
        skyline.push_back(virtual_last_point);            
        

        for(int i=0;i<buildings.size();i++){
            int new_point_left = buildings[i][0];
            int new_point_right = buildings[i][1];
            int new_point_height = buildings[i][2];
            PRINTF("[%d],[%d],[%d]\n",new_point_left,new_point_right,new_point_height);
            list<pair<int, int> >::iterator it;  
            for(it=skyline.begin();it!=skyline.end();it++){
                pair<int, int> &skypoint = *it;
				int &skypoint_x=skypoint.first;
				int &skypoint_y=skypoint.second;
				PRINTF("comparePoint_L[%d],[%d]\n",skypoint_x,skypoint_y);
                if(new_point_left > skypoint_x){
                    continue;
                }
                if(new_point_left == skypoint_x){
                    if(new_point_height > skypoint_y){
                        adjustHeight(skyline, it,new_point_height);
                    }
                    it++;
                    break;
                }else{
                    // new_point_left < skypoint_x
                    pair<int, int> &preskypoint = getPreOne(it);
					int preskypoint_y = preskypoint.second;
                    if(preskypoint_y<new_point_height){
						insertPoint(skyline,it,new_point_left,new_point_height);
                    }
                    break;
                }
                
            }
            
			
            for(;it!=skyline.end();it++){
                pair<int, int> &skypoint = *it;
				int &skypoint_x=skypoint.first;
				int &skypoint_y=skypoint.second;
				PRINTF("comparePoint_R[%d],[%d]\n",skypoint_x,skypoint_y);
                if(new_point_right < skypoint_x){
					pair<int, int> &preskypoint = getPreOne(it);
					int &preskypoint_y = preskypoint.second;
                    if(preskypoint_y == new_point_height){
						insertPoint(skyline,it,new_point_right,prePointBak.second);
                    }else if(preskypoint_y > new_point_height){
						// no need to insert point
					}else{
						// impossible
					}
                    break;
                }else if(new_point_right == skypoint_x){
					if(INT_MAX == new_point_right){
					    // insert a empty point
					    skyline.push_back(virtual_last_point);
					}
                    break;
                }else{
					//new_point_right > skypoint_x
					if(new_point_height >= skypoint_y){
						adjustHeight(skyline, it,new_point_height);
					}else{
						// nothing to do
					}
					

				}
            }
        }
		
		list<pair<int, int> >::iterator st=skyline.begin();
		list<pair<int, int> >::iterator ed=skyline.end();
		st++;ed--;
		result.assign(st,ed);
		return result;
    }
};