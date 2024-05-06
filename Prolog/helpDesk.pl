issue(system_crash,'reboot_pc').
issue(network_lost,'check_your_connection').

resolve_issue(Issue, Solution) :- issue(Issue, Solution), !.

resolve_issue(system_crash, Solution)