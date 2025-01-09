import 'package:flutter/material.dart';
import 'package:flutter_tutorial/stateless_wid.dart';

void main() {
  runApp(const MainApp());
}

class MainApp extends StatelessWidget {
  const MainApp({super.key});

  @override
  Widget build(BuildContext context) {
    
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      home: Stateless_wid(),
    );
  }
}
