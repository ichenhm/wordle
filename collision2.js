function max(x, y){
	return x > y ? x : y;
}
function min(x, y){
	return x < y ? x : y;
}
var Mask={
	top: 0,
	left: 0,
	width: 0,
	height: 0,
	pix: [],
	newMask: function (ctx, left, top, width, height){
		var obj = Object.create(Mask);
		var pixel = ctx.getImageData(left, top, width, height).data;
		var pixid = 0;
		obj.left = left;
		obj.top = top;
		obj.width = width;
		obj.height = height;
		obj.pix = new Array(height);
		
		for (var i = 0; i < height; i++){ 	
			obj.pix[i] = new Array(width);
			//pixid = ((top+i)*width+left)*4;//this is wrong
			pixid=(i*width)*4;//right
			for (var j = 0; j < width; j++){
				obj.pix[i][j] = pixel[ pixid + 3 ];
				pixid += 4;
				//if (obj.pix[i][j]>0&&op==3)console.log(33333333333,op,j,i);
				}
			}
		return obj;
	},
	
	intersect : function(x, y, oth){
		
		i_left=max(this.left, oth.left+x-oth.width/2);
		i_right=min(this.left + this.width, oth.left+x+oth.width/2);
		
		i_top=max(this.top, oth.top+y-oth.height/2);
		i_bottom=min(this.top + this.height, oth.top+y+oth.height/2);
		
		if (i_left > i_right) return false;
		if (i_top > i_bottom) return false;
		/*console.log(this.left,this.top,this.width,this.height);
		console.log(oth.left,oth.top,oth.width,oth.height);
		console.log(111111111,x,y);*/
		for (var i = i_left; i < i_right; i++)
			for (var j = i_top; j < i_bottom; j++)
				if (this.pix[j-this.top][i-this.left] > 0 && oth.pix[j-oth.top-y+oth.height/2][i-oth.left-x+oth.width/2] > 0) return true;
				
		return false;
	}
};