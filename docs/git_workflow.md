# Professional Git Workflow Guide

This document describes a recommended git workflow for professional software projects, including commit practices, issue tracking, merge requests, and deployment.

## 1. Branching Strategy

- **main**: Stable, production-ready code. Only merged after review and testing.
- **develop**: Active development branch. All features and fixes are merged here first.
- **feature/xxx**: For new features. Branch from `develop`.
- **bugfix/xxx**: For bug fixes. Branch from `develop`.
- **hotfix/xxx**: For urgent fixes. Branch from `main`.

## 2. Issue Tracking

- Use GitHub Issues (or your platform’s issue tracker) for all tasks, bugs, and feature requests.
- Each issue should have a clear title, description, and labels (e.g., bug, enhancement, documentation).
- Assign issues to team members and set milestones if needed.

## 3. Commit Practices

- Write clear, concise commit messages:
  - Use the present tense (e.g., "Add login feature")
  - Reference issues (e.g., "Fix #42: Correct login bug")
- Commit small, logical changes frequently.
- Avoid committing generated files, IDE configs, or build outputs.

## 4. Merge Requests (Pull Requests)

- Create a merge request (MR) or pull request (PR) for every change.
- Link the PR to the relevant issue(s).
- Request code review from team members.
- Ensure all tests pass before merging.
- Use "Squash and merge" to keep history clean if appropriate.

## 5. Deployment

- Tag releases on the `main` branch (e.g., `v1.0.0`).
- Use CI/CD pipelines for automated testing and deployment.
- Document deployment steps in the README or a dedicated file.
- After deployment, update the issue tracker and notify stakeholders.

## Example Workflow

1. **Create an issue** for a new feature:
   - Go to your repository's Issues tab and click "New Issue".
   - Fill in the title and description, add relevant labels (e.g., enhancement, bug), and assign it to a team member.
2. **Branch** from `develop`:
   - Update your local repository: `git fetch origin`
   - Switch to the develop branch: `git checkout develop`
   - Create a new feature branch: `git checkout -b feature/login`
3. **Commit** changes:
   - Make code changes related to the issue.
   - Stage your changes: `git add .`
   - Commit with a clear message referencing the issue: `git commit -m "Add login feature (#123)"`
4. **Push** branch:
   - Push your branch to the remote repository: `git push origin feature/login`
5. **Open a PR** to `develop`, link to issue #123:
   - Go to your repository on GitHub (or your platform).
   - Click "Compare & pull request" for your branch.
   - Set the base branch to `develop`.
   - Reference the issue in the PR description (e.g., "Closes #123").
   - Request reviews from team members.
6. **Review and merge** after approval:
   - Team members review the code, suggest changes, and approve.
   - Ensure all CI checks and tests pass.
   - Merge the PR using "Squash and merge" or "Rebase and merge" for a clean history.
7. **Deploy** from `main` after merging to `main` and tagging release:
   - Merge `develop` into `main`: `git checkout main && git merge develop`
   - Tag the release: `git tag v1.0.0 && git push origin v1.0.0`
   - Trigger your CI/CD pipeline or follow documented deployment steps.
   - Update the issue tracker and notify stakeholders of the deployment.

## Using Issue and Pull Request Templates Automatically

GitHub automatically uses templates placed in the `.github/ISSUE_TEMPLATE/` directory for issues and `.github/pull_request_template.md` for pull requests. No extra configuration is needed:
- When creating a new issue, GitHub will prompt you to select a template.
- When opening a pull request, the template will be pre-filled in the PR description.

For more details, see [GitHub Docs: Issue and Pull Request Templates](https://docs.github.com/en/issues/tracking-your-work-with-issues/creating-issue-templates-for-your-repository).

---

For more details, see [Atlassian Git Workflow](https://www.atlassian.com/git/tutorials/comparing-workflows) or [GitHub Flow](https://docs.github.com/en/get-started/quickstart/github-flow).
