/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
    var word = "" ;
    var ans = "" ;
    for (let i = 0 ; i < s.length ; i++) {
        if (s[i] == " ") {
            ans += reverse(word) ; 
            word = "" ;
            ans += " " ;
        } else {
            word += s[i] ;
        }
    }
    if (word != "") {
        ans += reverse(word) ;
    }
    return ans ;
};
var reverse = function(s) {
    if (s === "") {
        return "" ;
    } else {
        return reverse(s.substr(1)) + s.charAt(0) ;
    }
}