void main(){
	String name = "Hi this String contains whitespace";
	print(name);
	name.replaceAll('','');
	print(name);
	print(name.replaceAll(' ',''));
}