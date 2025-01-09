void main() {
  String name = "i am gautam";
  print("Original:  $name");
  print(name.removeWhiteSpaces()); 
  print(name.removeSpace);         
  print(name.removeSpaceWithThis()); 
}

extension StringExtension on String {
  // This is a method
  String removeWhiteSpaces() => replaceAll(' ', '').toUpperCase();

  // This is the getter approach
  String get removeSpace => replaceAll(' ', '');

	// Note: Both serve similar purposes, 
   // but getters are used without parentheses.
  // also using this on object , dart expilcity used this on the string object 
  // Explicitly using 'this' inside the method
  String removeSpaceWithThis() => this.replaceAll(' ', '');
}
