#!/usr/bin/python3
"""Reads from standard input and computes metrics.

After every ten lines or the input of a keyboard interruption (CTRL + C),
prints the following statistics:
    - Total file size up to that point.
    - Count of read status codes up to that point.
"""

import sys
from collections import defaultdict
from signal import signal, SIGINT
from datetime import datetime

"""Initialize variables"""
total_size = 0
status_code_counts = defaultdict(int)
lines_processed = 0
log_lines = []

"""Function to handle keyboard interrupt (CTRL+C)"""
def handle_interrupt(signal, frame):
    print_statistics()
    sys.exit(0)

"""Function to print statistics"""
def print_statistics():
    print(f"Total file size: {total_size}")
    for code in sorted(status_code_counts.keys()):
        print(f"{code}: {status_code_counts[code]}")

"""Register the signal handler"""
signal(SIGINT, handle_interrupt)

try:
    for line in sys.stdin:
        lines_processed += 1
        log_lines.append(line.strip())

        """Process every 10 lines"""
        if lines_processed % 10 == 0:
            for log_line in log_lines:
                """Extract relevant information from log line"""
                parts = log_line.split(" ")
                size = int(parts[-1])
                status_code = parts[-2]
                
                """Update total file size"""
                total_size += size

                """Update status code counts"""
                if status_code in ["200", "301", "400", "401", "403", "404", "405", "500"]:
                    status_code_counts[status_code] += 1

            """Print statistics"""
            print_statistics()

            """Reset variables"""
            total_size = 0
            status_code_counts = defaultdict(int)
            log_lines = []

except KeyboardInterrupt:
    """Handle keyboard interrupt (CTRL+C)"""
    handle_interrupt(signal.SIGINT, None)
