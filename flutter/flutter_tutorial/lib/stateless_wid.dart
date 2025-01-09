import 'package:flutter/material.dart';

class Stateless_wid extends StatelessWidget {
  Stateless_wid({super.key});

  int count = 0;
  @override
  Widget build(BuildContext context) {
    print('start');
    return Scaffold(
      body: Center(
        child: Column(
          children: [
            const Text('Hello World!'),
            const SizedBox(height: 10),
            Text(count.toString(), style: const TextStyle(fontSize: 30)),
            FloatingActionButton(
              onPressed: () {
                count++;
              },
              child: const Icon(Icons.add),
            ),
          ],
        ),
      ),
    );
  }
}
