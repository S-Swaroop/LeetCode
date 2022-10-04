/**
 * @param {number[][]} image
 * @param {number} sr
 * @param {number} sc
 * @param {number} color
 * @return {number[][]}
 */
var floodFill = function(image, sr, sc, color) {
    var dx = [-1 , 0 , 1 , 0] ; 
    var dy = [0 , -1 , 0 , 1] ;
    const n = image.length , m = image[0].length ;
    var startingColor = image[sr][sc] ;
    if (startingColor === color) {
        return image ;
    }
    const isValid = (x , y) => {
        return (x >= 0 && y >= 0 && x < n && y < m && image[x][y] === startingColor) ;
    }
    
    const dfs = (x , y) => {
        image[x][y] = color ; 
        for (let i = 0 ; i < 4 ; i++) {
            if (isValid(x + dx[i] , y + dy[i])) {
                dfs (x + dx[i] , y + dy[i]) ;
            }
        }
    } ;
    dfs (sr , sc) ;
    return image ;
};
