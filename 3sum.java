public class Solution {
    public List<List<Integer>> threeSum(int[] num) {
		int len=num.length;
		Arrays.sort(num);
		List<List<Integer>> result=new ArrayList<List<Integer>>();
		HashMap<Integer,Integer> map=new HashMap<Integer,Integer>();
		HashMap<Integer,Integer> dataNum=new HashMap<Integer,Integer>();

		for(int i=0;i<len;i++){
			int first=num[i];
			if(null==dataNum.get(first)){
				//System.out.println(first);
				dataNum.put(first,1);
			}else{
				// skip duplicated data, very important
				// 1. skip data already calced. 2. decrease the execution time 
				continue;
			}
			
			map.clear();
			for(int j=i+1;j<len;j++){
				int third = num[j];
				int second = 0-first-third;
				if(null!=map.get(third)){
				    if(1==map.get(third)){
						List<Integer> list=new ArrayList<Integer>();
    					list.add(first);
    					list.add(second);
    					list.add(third);
    					result.add(list);		        
				        map.put(third,0);
				    }
					
				}else{
					map.put(second,1);
				}
			}
		}
		
		return result;
    }
}
