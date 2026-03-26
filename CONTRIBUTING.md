
## Contributing to velocache
Thank you for your interest in contributing to velocache! We aim to build a high-performance cache-like tool.

 Whether you’re fixing a bug, adding a new feature, or optimizing data structures used , your help is welcome.

### Development Setup
To set up your local development environment and build the project, please follow the installation instructions in the [README.md](README.md#installation--build).

*Additional Dev Note: Ensure you have `g++` or `make` installed, as our build process relies on standard GNU tools*.


### Development Workflow
- **Code Style:** Keep it clean and readable. Use standard C++17/20 practices.

- **Performance:** velocache’s core goal is low overhead. Any new feature should have a minimal footprint on system resources.

- **Testing:** If you add a new metric or tests(e.g., Disk I/O, CPU stats, or benchmarks), please ensure it is modular and doesn't break the **apps/server.cpp**.

### How to Contribute
1. **Fork** the repository.

2. Create a **new branch** for your feature: `git checkout -b feature/your-feature-name`.

3. **Commit** your changes with clear, descriptive messages.

4. **Push** your branch and open a **Pull Request**.

### Current Priorities

Looking for a place to start?
Check the [ROADMAP](assets/docs/roadmap.md) for planned ideas
    
or consider **user-defined** ideas to make velocache better. Some easy wins: 
- Code refractoring
- Terminal UI improvement
- Documentation(like architecture or usage docs)
- Submitting issues or engaging in discussions