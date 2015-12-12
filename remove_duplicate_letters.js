

var findFromA = function(iResult, iValues, str, st){

    for(var i=0;i<26;i++){

        for(var tmp=iValues[i].length-1;tmp>=0;tmp--){

            if(iValues[i][tmp]<st){

                iValues[i].splice(0,tmp+1);

                break;

            }

        }

        if(0===iValues[i].length){

            continue;

        }

        

        

        var compareV = iValues[i][0];

        var yes=true;

        for(var k=0;k<26;k++){

            var kLen=iValues[k].length;

            if(0===kLen)continue;

            if(compareV > iValues[k][kLen-1]){

                yes=false;

                break;

            }

        }

        if(!yes){

            continue;

        }

        //console.log(compareV);

        iResult.push(str[compareV]);

        iValues[i] = [];

        return findFromA(iResult, iValues, str, compareV+1);



    }

}





var removeDuplicateLetters = function(s) {

    if(s.length<=1)return s;



    var iResult=[];

    var iValues=[];

    for(var i=0;i<26;i++){

        iValues.push([]);

    }

    for(var i=0;i<s.length;i++){

        iValues[s[i].charCodeAt(0)-"a".charCodeAt(0)].push(i);

    }



    findFromA(iResult, iValues, s, 0);

    

    return iResult.join('');

    

};
