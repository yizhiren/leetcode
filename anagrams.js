/**
 * @param {string[]} strs
 * @return {string[]}
 */

var sortStr = function(str) {
    return str.split('').sort().join('');
}
var anagrams = function(strs) {
    var obj={};
    for(var i=0,len=strs.length;i<len;i++){
        var sortedStr = sortStr(strs[i]);
        if(!obj[sortedStr]){
            obj[sortedStr]=[];
        }
        obj[sortedStr].push(strs[i]);
    }
    var result=[];
    for (var sortedkey in obj){
        var arr=obj[sortedkey];
        if(arr.length>1){
            result=result.concat(arr);
        }
    }
    return result;
    
};
