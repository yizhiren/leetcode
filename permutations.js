/**
 * @param {number[]} num
 * @return {number[][]}
 */

var result=[];
var dataNum={}; //map
var dataArr=[]; //array
var numLen;

var oneAns=[];
var permute = function(num) {
    numLen=num.length;
    if(numLen==0)
        return result;
        
    result=[];
    dataNum={}; //map
    dataArr=[]; //array
    oneAns=[];
    
    for(var i=0;i<num.length;i++){
        console.log(num[i],dataNum[num[i]]);
        if(!dataNum[num[i]]){
            
            dataArr.push(num[i]);
            dataNum[num[i]]=0;
        }
        console.log(num[i],dataNum[num[i]]);
        dataNum[num[i]]++;
        console.log(num[i],dataNum[num[i]]);
    }
    console.log(dataNum);
    console.log(dataArr);
    console.log(numLen);
    job(0);
    return result;
};


var job=function(index){
    for(var i=0;i<dataArr.length;i++){
        var thedata=dataArr[i];
        if(dataNum[thedata]<=0){
            continue;
        }
        dataNum[thedata]--;
        oneAns[index]=thedata;
        if(index==numLen-1){
            result.push(oneAns.slice(0));
        }else{
            job(index+1);
        }
        dataNum[thedata]++;
    }
}



