import 'dart:io';

void main(){
	print("Enter your name: ");
	String? name= stdin.readLineSync();

	stdout.write("Hi i am $name");
}