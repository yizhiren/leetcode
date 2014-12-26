/*
c++ hashmap using fail ,so such case ,use java instead.
*/
public class Solution {
    public List<List<Integer>> fourSum(int[] num, int target) {
        int len=num.length;
		HashSet<List<Integer>> result=new HashSet<List<Integer>>();
		HashMap<Integer,List<Integer>> twoSumMap = new HashMap<Integer,List<Integer>>();
		for(int i=0;i<len;i++){
			int first=num[i];
			for(int j=i+1;j<len;j++){
				int second=num[j];
				int twosum = first+second;
				if(null!=twoSumMap.get(target-twosum)){
					List<Integer> pairs=twoSumMap.get(target-twosum);
					for(int k=0;k<pairs.size();k+=2){
					    if(i==pairs.get(k)
						|| i==pairs.get(k+1)
						|| j==pairs.get(k)
						|| j==pairs.get(k+1)){
							continue;
						}
						List<Integer> list=new ArrayList<Integer>();
						list.add(num[pairs.get(k)]);
						list.add(num[pairs.get(k+1)]);
						list.add(num[i]);
						list.add(num[j]);
						Collections.sort(list);
						result.add(list);
					}
					
				}

			}
			for(int j=i+1;j<len;j++){
				int second=num[j];
				int twosum = first+second;
				if(null==twoSumMap.get(twosum)){
					twoSumMap.put(twosum,new ArrayList<Integer>());
				}
				twoSumMap.get(twosum).add(i);
				twoSumMap.get(twosum).add(j);
			}
		}
		return new ArrayList<List<Integer>>(result);
    }
	
}
