/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function(s) {
    var words=s.trim().split(/[ ]+/);
    var len=words.length;
    return words[len-1].length;
};